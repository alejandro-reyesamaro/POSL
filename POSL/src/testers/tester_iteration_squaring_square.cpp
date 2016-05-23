#include "tester_iteration_squaring_square.h"
#include "../tools/tools.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_element_changed_neighborhood.h"
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

Tester_IterationSquaringSquare::Tester_IterationSquaringSquare(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_IterationSquaringSquare::test()
{
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    shared_ptr<Benchmark> bench(make_shared<SquaringSquare>(10,squares));
    vector<int> config({2, 0, 6, 1, 5, 7, 0, 2, 1, 6, 8, 2, 0, 4});
    //vector<int> config({0, 0, 6, 4, 5, 7, 4,       0, 6, 0, 6, 6, 7, 7});
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Variable_Domain(), config));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    int c = bench->solutionCost(sol);
    //cout << "Initial cost (54): " << c << endl;

    psp->Start(sol->get_conf_by_ref());
    vector<int> config2({2, 0, 7, 1, 5, 7, 0, 2, 1, 1, 8, 2, 0, 4});
    //vector<int> config2({0, 0, 6, 4, 4, 7, 4,      0, 6, 0, 6, 6, 7, 7}); //({0, 0, 6, 4, 5, 7, 4,      0, 6, 0, 6, 6, 3, 7});
    int rc = bench->relativeSolutionCost(config2);
    //int ac = bench->solutionCost(config2);

    //cout << "Cost (86) ? -> " << rc << " - " << ac << endl;


    vector<int> config3({0, 0, 6, 4, 6, 7, 4, 0, 6, 0, 6, 6, 7, 7});
    sol = make_shared<Solution>(bench->Variable_Domain(), config3);
    psp = make_shared<PSP>(bench);
    int c3 = bench->solutionCost(sol);
    cout << "Initial cost (12): " << c3 << endl;

    shared_ptr<CompoundModule> OM_S (make_shared<OM_FixedFirstConfiguration>(bench, config3));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_OneElementChangedNeighborhood>(bench));
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
    cout << sol->configurationToString() << endl;
    int c2 = bench->solutionCost(sol);
    cout << "Final cost: " << Tools::int2str(c2) << endl;

    return ( c == 54 && rc == 86 ) ?
           "One Iteration (Squaring Square): OK !" : "One Iteration (Squaring Square): fail :/";
}
