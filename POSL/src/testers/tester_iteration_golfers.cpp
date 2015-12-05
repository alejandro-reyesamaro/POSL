#include "tester_iteration_golfers.h"
#include "../tools/tools.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_first_improvement_selection.h"
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

Tester_IterationGolfers::Tester_IterationGolfers(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_IterationGolfers::test()
{
    shared_ptr<Benchmark> bench332(make_shared<Golfers>(3,3,2));
    vector<int> init_config = Tester::Golfers_332_c6();
    shared_ptr<Solution> sol332(make_shared<Solution>(bench332->Domains(), init_config));
    shared_ptr<PSP> psp332(make_shared<PSP>(bench332));
    int cA = bench332->solutionCost(sol332);
    //cout << "Initial cost: " << cA << endl;

    psp332->Start(sol332->GetConfiguration());

    vector<int> cc(init_config.size());
    copy(init_config.begin(), init_config.end(), cc.begin());

    cc[10] = 9;
    cc[15] = 4;

    int cR1;
    cR1 = bench332->relativeSolutionCost(cc);
    //cout << "Costo 4 ? -> " << cR1 << endl;

    cc[14] = 1;
    cc[16] = 8;

    //int cR2 = bench332->relativeSolutionCost(cc);
    //cout << "Costo 0 ? -> " << cR2 << endl;

    bool ok = cA == 6 && cR1 == 4;// && cR2 == 0;
    // ************************************************

    copy(init_config.begin(), init_config.end(), cc.begin());
    cc[10] = 9;
    cc[15] = 4;

    psp332->UpdateSolution(cc);

    int current_cost = psp332->CurrentCost();
    //cout << current_cost << endl;

    cc[14] = 1;
    cc[16] = 8;

    cR1 = psp332->GetBenchmark()->relativeSolutionCost(cc);
    //cout << cR1 << endl;

    ok = ok && current_cost == 4 && cR1 == 0;
    // ************************************************

    //shared_ptr<CompoundModule> OM_S (make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench332));
    shared_ptr<CompoundModule> OM_S_ (make_shared<OM_FixedFirstConfiguration>(bench332));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_GolfersSingleSwapNeighborhood>(bench332));
    shared_ptr<CompoundModule> OM_SS (make_shared<OM_FirstImprovementSelection>(bench332));
    shared_ptr<CompoundModule> OM_D (make_shared<OM_AlwaysImproveDecision>());

    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(OM_S_, OM_V));
    shared_ptr<GroupedComputation> Gsec1(make_shared<GroupedSequentialComputation>(sec_1));

    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(Gsec1, OM_SS));
    shared_ptr<GroupedComputation> Gsec2(make_shared<GroupedSequentialComputation>(sec_2));

    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(Gsec2, OM_D));
    shared_ptr<GroupedComputation> Gsec3(make_shared<GroupedSequentialComputation>(sec_3));

    psp332->UpdateSolution(sol332->GetConfiguration());
    shared_ptr<Solution> sol = static_pointer_cast<Solution>(Gsec3->execute(psp332, t_seed));
    //cout << sol->configurationToString() << endl;
    //cout << "Final cost: " << Tools::int2str(bench332->solutionCost(sol)) << endl;

    shared_ptr<Benchmark> bench554(make_shared<Golfers>(5,5,4));
    vector<int> init_config2 = Tester::Golfers_554_c0();

    shared_ptr<Solution> sol554(make_shared<Solution>(bench554->Domains(), init_config2));
    shared_ptr<PSP> psp554(make_shared<PSP>(bench554));
    int c554 = bench332->solutionCost(sol554);
    cout << "Initial cost: " << c554 << endl;
    psp554->Start(sol554->GetConfiguration());
    int c554A = psp554->CurrentCost();
    cout << "Relative cost: " << c554A << endl;

    init_config2[1] = 7;
    init_config2[6] = 2;

    int rc554 = bench554->relativeSolutionCost(init_config2);
    cout << "Relative cost: " << rc554 << endl;

    return (ok  ) ?
           "One Iteration (Golfers): OK !" : "One Iteration (Golfers): fail :/";
}
