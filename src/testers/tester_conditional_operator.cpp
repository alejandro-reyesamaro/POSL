#include "tester_conditional_operator.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/cyclic_operator.h"
#include "../operators/conditional_operator.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/reached_cost_expression.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../tools/tools.h"

Tester_ConditionalOperator::Tester_ConditionalOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_ConditionalOperator::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol1(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_c4()));
    shared_ptr<Solution> sol2(make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_mal()));

    //int c1 = psp->GetBenchmark()->solutionCost(sol1);
    //int c2 = psp->GetBenchmark()->solutionCost(sol2);

    //cout << c1 << " and " << c2 << endl;

    bench->SetDefaultConfiguration(sol1->get_conf_by_ref());

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2_1(make_shared<OM_OneElementChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm2_2(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_BestImprovementSelection>(bench));
    shared_ptr<CompoundModule> cm4(make_shared<OM_AlwaysImproveDecision>());

    // cm2_1 <cond> cm2_2
    shared_ptr<Operator> op0(make_shared<ConditionalOperator>(cm2_1, cm2_2, make_shared<ReachedCostExpression>(10)));

    // [ cm2_1 <cond> cm2_2 ]:
    shared_ptr<GroupedComputation> G22(make_shared<GroupedSequentialComputation>(op0));

    // cm1 |-> [ cm2_1 <cond> cm2_2 ] :
    shared_ptr<Operator> op1(make_shared<SequentialExecOperator>(cm1, G22));

    // [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ]:
    shared_ptr<GroupedComputation> G12(make_shared<GroupedSequentialComputation>(op1));

    // [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3 :
    shared_ptr<Operator> op2(make_shared<SequentialExecOperator>(G12, cm3));

    // [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] :
    shared_ptr<GroupedComputation> G123(make_shared<GroupedSequentialComputation>(op2));

    // [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] |-> cm4 :
    shared_ptr<Operator> op3(make_shared<SequentialExecOperator>(G123, cm4));

    // [ [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] |-> cm4 ] :
    shared_ptr<GroupedComputation> G1234(make_shared<GroupedSequentialComputation>(op3));

    shared_ptr<Solution> after_sol1 = static_pointer_cast<Solution>(G1234->execute(psp, t_seed));
    int cost1 = psp->GetBenchmark()->solutionCost(after_sol1);

    psp->UpdateSolution(sol2->get_conf_by_ref());

    shared_ptr<Solution> after_sol2 = static_pointer_cast<Solution>(G1234->execute(psp, t_seed));
    int cost2 = psp->GetBenchmark()->solutionCost(after_sol2);

    cout << cost1 << " and " << cost2 << endl;
    return "Conditional Operator: OK ! (go to the OMs for cheking)";
}
