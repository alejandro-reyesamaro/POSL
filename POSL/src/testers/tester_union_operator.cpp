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

    Benchmark * bench = new Golfers(4,4,2);
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


    //Benchmark * bench = new GolombRuler(12, 85);
    //vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    PSP * psp = new PSP(ARGC, ARGV, bench);
    Solution * sol = new Solution(psp->GetBenchmark()->Domains(), config);

    OperationModule * m1 = new OM_MultiElementsChangedNeighborhood(bench);
    OperationModule * m2 = new OM_OneElementChangedNeighborhood(bench);

    Operator * op = new UnionOperator(m1, m2);

    CompoundModule * G1 = (comp == SEQ)
            ? (CompoundModule *) new GroupedSequentialComputation(op)
            : (CompoundModule *) new GroupedParallelComputation(op);

    Neighborhood * V = (Neighborhood *)G1->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
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


