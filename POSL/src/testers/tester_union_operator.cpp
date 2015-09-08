#include "tester_union_operator.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../operators/union_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/grouped_parallel_computation.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../computation/flag_computation.h"

Tester_UnionOperator::Tester_UnionOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_UnionOperator::testeInMode(Computation comp)
{

    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    vector<int> config(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1
    });


    //Benchmark> bench(make_shared<GolombRuler(12, 85);
    //vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));
    shared_ptr<Solution> sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));

    shared_ptr<OperationModule> m1(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<OperationModule> m2(make_shared<OM_OneElementChangedNeighborhood>(bench));

    shared_ptr<Operator> op(make_shared<UnionOperator>(m1, m2));

    shared_ptr<CompoundModule> G1 = (comp == SEQ)
            ? static_pointer_cast<CompoundModule>(make_shared<GroupedSequentialComputation>(op))
            : static_pointer_cast<CompoundModule>(make_shared<GroupedParallelComputation>(op));

    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(G1->execute(psp, sol));

    shared_ptr<POSL_Iterator<vector<int>>> it = V ->getIterator();
    it->Reset();
    int changes = 0;
    bool the_changes = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        //cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            if(*j != 1) changes ++;
            //cout << *j << " ";
        }
        //cout << "]" << endl;
        the_changes = the_changes && (changes == 5 || changes == 1);
        changes = 0;
    }
    string mode_str = (comp == SEQ) ? "Operator_Union (Sequential)" : "Operator_Union (Parallel)";
    return (the_changes) ? mode_str + ": OK !" : mode_str + ": fail :/";
}

string Tester_UnionOperator::test()
{
    //return testeInMode(SEQ);
    return testeInMode(SEQ) + "\n   " + testeInMode(PAR);
}


