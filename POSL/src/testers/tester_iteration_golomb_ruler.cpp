#include "tester_iteration_golomb_ruler.h"
#include "../tools/tools.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
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

Tester_IterationGolombRuler::Tester_IterationGolombRuler(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_IterationGolombRuler::test()
{
    //0, 1, 4, 10, 12, 17
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6,17));
    vector<int> init_config ({0, 1, 4, 8, 12, 17});
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Variable_Domain(), init_config));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    int c = bench->solutionCost(sol);
    //cout << "Initial cost (3): " << c << endl;

    psp->Start(sol->get_conf_by_ref());

    vector<int> cc(init_config.size());
    //copy(init_config.begin(), init_config.end(), cc.begin());

    cc[3] = 5;

    c = bench->relativeSolutionCost(cc);
    //cout << "Cost (4) ? -> " << c << endl;

    cc[3] = 10;

    c = bench->relativeSolutionCost(cc);
    //cout << "Final Cost (0) ? -> " << c << endl;


    shared_ptr<CompoundModule> OM_S (make_shared<OM_FixedFirstConfiguration>(bench, init_config));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_OneSortedChangeNeighborhood>(bench));
    shared_ptr<CompoundModule> OM_SS (make_shared<OM_BestImprovementSelection>(bench));
    shared_ptr<CompoundModule> OM_D (make_shared<OM_AlwaysImproveDecision>());

    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(OM_S, OM_V));
    shared_ptr<GroupedComputation> Gsec1(make_shared<GroupedSequentialComputation>(sec_1));

    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(Gsec1, OM_SS));
    shared_ptr<GroupedComputation> Gsec2(make_shared<GroupedSequentialComputation>(sec_2));

    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(Gsec2, OM_D));
    shared_ptr<GroupedComputation> Gsec3(make_shared<GroupedSequentialComputation>(sec_3));

    psp->UpdateSolution(sol->get_conf_by_ref());
    sol = static_pointer_cast<Solution>(Gsec3->execute(psp, t_seed));
    //cout << sol->configurationToString() << endl;
    c = bench->solutionCost(sol);
    //cout << "Final cost: " << Tools::int2str(c) << endl;

    return ( c == 0 ) ?
           "One Iteration (Golomb Ruler): OK !" : "One Iteration (Golomb Ruler): fail :/";
}
