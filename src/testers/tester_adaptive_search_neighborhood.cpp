#include "tester_adaptive_search_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_adaptive_search_neighborhood.h"
#include "../modules/om_adaptive_search_range_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_permutation_generation.h"
#include "../tools/tools.h"

Tester_AdaptiveSearchNeighborhood::Tester_AdaptiveSearchNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_AdaptiveSearchNeighborhood::test()
{
    vector<int> config1({ 0, 2, 4, 6, 1, 7, 3, 5 });

    shared_ptr<Benchmark> bench(make_shared<NQueens>(4000));
    bench->SetDefaultConfiguration(config1);

    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //shared_ptr<OperationModule> om_s(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<OperationModule> om_s(make_shared<OM_RandomPermutationGeneration>(bench));
    //shared_ptr<OperationModule> om_v(make_shared<OM_AdaptiveSearchNeighborhood>(bench));
    shared_ptr<OperationModule> om_v(make_shared<OM_AdaptiveSearchRangeNeighborhood>(bench, 2000, 3000));
    shared_ptr<Operator> op(make_shared<SequentialExecOperator>(om_s, om_v));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(G->execute(psp, t_seed));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();
    //int sum  = 0;
    //int prod = 1;
    bool only_change_one = true;

    //cout << Tools::configurationToString(config1) << endl;

    /*
    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            int k = *j;
            sum  += k;
            prod *= k;
        }
        shared_ptr<Solution> aux(make_shared<Solution>(bench->Variable_Domain(), neighbor));
        cout << aux->configurationToString() << endl;
    }
    */
    return (only_change_one) ? "OM_AdaptiveSearchNeighborhood: OK !" : "OM_AdaptiveSearchNeighborhood: fail :/";
}
