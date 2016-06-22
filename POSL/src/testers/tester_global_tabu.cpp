#include "tester_global_tabu.h"

#include "../data/solution.h"
#include "../tools/tools.h"
#include "../tools/tabu_list.h"

#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../modules/om_tabu_processing.h"

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

Tester_GlobalTabu::Tester_GlobalTabu(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_GlobalTabu::test()
{    
    vector<int> init_config ({0, 1, 4, 8, 12, 17});
    shared_ptr<TabuList> tl(make_shared<TabuList>(2));
    tl->push(init_config);
    bool tabu = true;

    vector<int> new_config1 ({0, 3, 4, 8, 12, 17});
    tabu = tabu && tl->isTabuByNorm1(new_config1, 3);
    vector<int> new_config2 ({1, 2, 3, 6, 10, 15});
    tabu = tabu && tl->isTabuByNorm2(new_config2, 4);
    vector<int> new_config3 ({1, 3, 7, 12, 17, 23});
    tabu = tabu && ! tl->isTabuByNorm2(new_config3, 9);
    tabu = tabu && tl->isTabuByNorm8(new_config3, 7);

    vector<int> new_config4({3, 5, 10, 1, 2, 3});
    vector<int> new_config5({4, 6, 12, 0, 1, 2});
    tl->push(new_config4);
    tl->push(new_config5);

    tabu = tabu && ! tl->isTabuByNorm1(new_config1, 3);

    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(10,55));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<CompoundModule> OM_S (make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_OneSortedChangeNeighborhood>(bench));
    shared_ptr<CompoundModule> OM_SS (make_shared<OM_BestImprovementSelection>(bench));
    shared_ptr<CompoundModule> OM_D (make_shared<OM_AlwaysImproveDecision>());
    shared_ptr<CompoundModule> OM_R (make_shared<OM_TabuProcessing>());

    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(OM_S, OM_V));
    shared_ptr<GroupedComputation> Gsec1(make_shared<GroupedSequentialComputation>(sec_1));

    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(Gsec1, OM_SS));
    shared_ptr<GroupedComputation> Gsec2(make_shared<GroupedSequentialComputation>(sec_2));

    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(Gsec2, OM_D));
    shared_ptr<GroupedComputation> Gsec3(make_shared<GroupedSequentialComputation>(sec_3));

    shared_ptr<Operator> sec_4(make_shared<SequentialExecOperator>(Gsec3, OM_R));
    shared_ptr<GroupedComputation> Gsec4(make_shared<GroupedSequentialComputation>(sec_4));

    vector<int> init_config2 ({0, 1, 3, 6, 10, 15, 21, 28, 37, 55});
    bench->SetDefaultConfiguration(init_config2);
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Variable_Domain(), init_config2));
    psp->UpdateSolution(sol->get_conf_by_ref());
    sol = static_pointer_cast<Solution>(Gsec4->execute(psp, t_seed));

    return (tabu) ? "Global Tabu: OK !" : "Global Tabu: fail :/";
}
