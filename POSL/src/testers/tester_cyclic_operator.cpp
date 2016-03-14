#include "tester_cyclic_operator.h"

#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_always_improve_decision.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/cyclic_operator.h"
#include "../expressions/loop_bound_expression.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../tools/tools.h"

Tester_CyclicOperator::Tester_CyclicOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_CyclicOperator::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm0(make_shared<OM_RandomConfGeneration>(bench));
    //shared_ptr<CompoundModule> cm2(make_shared<OM_OneElementChangedNeighborhood();
    shared_ptr<CompoundModule> cm2(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<CompoundModule> cm3(make_shared<OM_BestImprovementSelection>(bench));
    shared_ptr<CompoundModule> cm4(make_shared<OM_AlwaysImproveDecision>());

    shared_ptr<Solution> first_solution = static_pointer_cast<Solution>(cm0->execute(psp, t_seed));
    int first_cost = psp->GetBenchmark()->solutionCost(first_solution);

    // cm2 |-> cm3 :
    shared_ptr<Operator> op0(make_shared<SequentialExecOperator>(cm2, cm3));

    // [ cm2 |-> cm3 ]:
    shared_ptr<GroupedComputation> G23(make_shared<GroupedSequentialComputation>(op0));

    // [ cm2 |-> cm3 ] |-> cm4 :
    shared_ptr<Operator> op1(make_shared<SequentialExecOperator>(G23, cm4));

    // [ [ cm2 |-> cm3 ] |-> cm4] ] :
    shared_ptr<GroupedComputation> G234(make_shared<GroupedSequentialComputation>(op1));

    // Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } :
    shared_ptr<Operator> op2(make_shared<CyclicOperator>(G234, make_shared<LoopBoundExpression>(1000)));

    // [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ] :
    shared_ptr<GroupedComputation> Gcyc(make_shared<GroupedSequentialComputation>(op2));

    // cm1 |-> [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ]
    shared_ptr<Operator> op3(make_shared<SequentialExecOperator>(cm1, Gcyc));

    // [ cm1 |-> [ Cyc(100 lopps){ [ [ cm2 |-> cm3 ] |-> cm4] ] } ] ]
    shared_ptr<GroupedComputation> G3(make_shared<GroupedSequentialComputation>(op3));

    psp->UpdateSolution(first_solution->get_conf_by_ref());
    shared_ptr<Solution> best_solution = static_pointer_cast<Solution>(G3->execute(psp, t_seed));


    int cost = psp->GetBenchmark()->solutionCost(best_solution);

    string prefix = "Costs: " + Tools::int2str(first_cost) + " - " + Tools::int2str(cost);
    return (first_cost >= cost) ? prefix + " -> Cyclic Operator: OK !" : "Cyclic Operator: fail :/";
}
