#include "tester_iteration_all_intervals.h"
#include "../tools/tools.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_all_permutations_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"

#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/cyclic_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../expressions/reached_cost_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/same_cost_iterations_bound_expression.h"
#include "../expressions/or_expression.h"
#include "../expressions/and_expression.h"

#include <algorithm>

Tester_IterationAllIntervals::Tester_IterationAllIntervals(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_IterationAllIntervals::test()
{
    shared_ptr<Benchmark> bench(make_shared<AllIntervals>(10));
    //  vector<int> all1( { 8, 0, 9, 2, 6, 1, 7, 4, 5, 3 }); // 0
    //vector<int> all_init( { 7, 0, 9, 2, 6, 1, 8, 4, 5, 3 }); // 17
    //vector<int> all_init( { 7, 0, 5, 2, 6, 1, 8, 4, 9, 3 }); //20
    //vector<int> all_init( { 7, 4, 5, 2, 6, 1, 8, 0, 9, 3 }); // 2
    vector<int> all_init( { 0, 6, 2, 5, 3, 4, 1, 7, 9, 8 }); // 10
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Variable_Domain(), all_init));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    int c = bench->solutionCost(sol);
    cout << "Initial cost : " << c << endl;

    //psp->Start(sol->get_conf_by_ref());

    bench->SetDefaultConfiguration(all_init);

    shared_ptr<CompoundModule> OM_S (make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_AllPermutationsNeighborhood>(bench, 1));
    shared_ptr<CompoundModule> OM_SS (make_shared<OM_BestImprovementSelection>(bench));
    shared_ptr<CompoundModule> OM_D (make_shared<OM_AlwaysImproveDecision>());

    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(OM_S, OM_V));
    shared_ptr<GroupedComputation> Gsec1(make_shared<GroupedSequentialComputation>(sec_1));

    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(Gsec1, OM_SS));
    shared_ptr<GroupedComputation> Gsec2(make_shared<GroupedSequentialComputation>(sec_2));

    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(Gsec2, OM_D));
    shared_ptr<GroupedComputation> Gsec3(make_shared<GroupedSequentialComputation>(sec_3));

    //psp->UpdateSolution(sol->get_conf_by_ref());
    sol = static_pointer_cast<Solution>(Gsec3->execute(psp, t_seed));
    cout << sol->configurationToString() << endl;
    int cc = bench->solutionCost(sol);
    cout << "Final cost: " << Tools::int2str(cc) << endl;

    return ( c == 17 && cc == 0) ?
           "One Iteration (All-Intervals): OK !" : "One Iteration (All-Intervals): fail :/";
}
