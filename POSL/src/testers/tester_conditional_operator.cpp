#include "tester_conditional_operator.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_always_improve_decition.h"
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
    vector<int> config0(
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

    vector<int> config1( // pas trop mal
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    vector<int> config2( // mal
    {
        1,  4,   3,  4,
        4,  4,   7,  8,
        9,  4, 11, 12,
        4, 4, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    //PSP * psp = new PSP(bench);
    Solution * sol1 = new Solution(psp->GetBenchmark()->GetSolution()->domains, config1);
    Solution * sol2 = new Solution(psp->GetBenchmark()->GetSolution()->domains, config2);

    //int c1 = psp->GetBenchmark()->solutionCost(sol1);
    //int c2 = psp->GetBenchmark()->solutionCost(sol2);

    //cout << c1 << " and " << c2 << endl;

    psp->UpdateSolution(sol1);

    CompoundModule * cm1 = new OM_FixedFirstConfiguration();
    CompoundModule * cm2_1 = new OM_OneElementChangedNeighborhood();
    CompoundModule * cm2_2 = new OM_MultiElementsChangedNeighborhood();
    CompoundModule * cm3 = new OM_BestImprovementSelection();
    CompoundModule * cm4 = new OM_AlwaysImproveDecition();

    // cm2_1 <cond> cm2_2
    Operator * op0 = new ConditionalOperator(cm2_1, cm2_2, new ReachedCostExpression(10));

    // [ cm2_1 <cond> cm2_2 ]:
    GroupedComputation * G22 = new GroupedSequentialComputation(op0);

    // cm1 |-> [ cm2_1 <cond> cm2_2 ] :
    Operator * op1 = new SequentialExecOperator(cm1, G22);

    // [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ]:
    GroupedComputation * G12 = new GroupedSequentialComputation(op1);

    // [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3 :
    Operator * op2 = new SequentialExecOperator(G12, cm3);

    // [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] :
    GroupedComputation * G123 = new GroupedSequentialComputation(op2);

    // [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] |-> cm4 :
    Operator * op3 = new SequentialExecOperator(G123, cm4);

    // [ [ [ cm1 |-> [ cm2_1 <cond> cm2_2 ] ] |-> cm3] ] |-> cm4 ] :
    GroupedComputation * G1234 = new GroupedSequentialComputation(op3);

    // MAL!!!!!
    Solution * after_sol1 = (Solution *)G1234->execute(psp, sol1);
    //int cost1 = psp->GetBenchmark()->solutionCost(after_sol1);

    psp->UpdateSolution(sol2);
    Solution * after_sol2 = (Solution *)G1234->execute(psp, sol2);
    //int cost2 = psp->GetBenchmark()->solutionCost(after_sol2);

    //cout << cost1 << " and " << cost2 << endl;
    return "Conditional Operator: OK ! (go to the OMs for cheking)";
}
