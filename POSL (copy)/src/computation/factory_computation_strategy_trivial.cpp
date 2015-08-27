#include "factory_computation_strategy_trivial.h"

#include "../operators/sequential_exec_operator.h"
#include "../operators/cyclic_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/oms_iterations_counter.h"
#include "../modules/oms_time_counter.h"
#include "../expressions/loop_bound_expression.h"

FactoryComputationStrategy_Trivial::FactoryComputationStrategy_Trivial(
        AOM_FirstConfigurationGeneration * first_conf_generation,
        AOM_NeighborhoodFunction * neighborhood_function,
        AOM_SelectionFunction * selection_function,
        AOM_DecisionFunction * decision_fucntion,
        int loops_main_cycle)
{
    CompoundModule * cm_iter  = new OMS_IterationsCounter();
    CompoundModule * cm_time  = new OMS_TimeCounter();

    // neighborhood |-> selection :
    Operator * sec_1 = new SequentialExecOperator(neighborhood_function, selection_function);

    // [ neighborhood |-> selection ] :
    GroupedComputation * G_sec1 = new GroupedSequentialComputation(sec_1);

    // [ neighborhood |-> selection ]  |-> decision :
    Operator * sec_2 = new SequentialExecOperator(G_sec1, decision_fucntion);

    // [ [ neighborhood |-> selection ]  |-> decision ]:
    GroupedComputation * G_sec2 = new GroupedSequentialComputation(sec_2);


    // Adding an iterations counter :
    // <--------------------------------------------------------------------------------->
    Operator * sec_3 = new SequentialExecOperator(G_sec2, cm_iter);
    GroupedComputation * G_sec3 = new GroupedSequentialComputation(sec_3);
    // <--------------------------------------------------------------------------------->

    // Adding a time measurer :
    // <--------------------------------------------------------------------------------->
    Operator * sec_4 = new SequentialExecOperator(G_sec3, cm_time);
    GroupedComputation * G_sec4 = new GroupedSequentialComputation(sec_4);
    // <--------------------------------------------------------------------------------->


    // Cyc(n lopps){ G_sec4 } :
    Operator * cyc1 = new CyclicOperator(G_sec4, new LoopBoundExpression(loops_main_cycle));

    // [ Cyc(n lopps){ G_sec4 } ]:
    GroupedComputation * G_cyc1 = new GroupedSequentialComputation(cyc1);

    // first_config |-> [ Cyc(n lopps){ G_sec4 } ]
    Operator* sec_0 = new SequentialExecOperator(first_conf_generation, G_cyc1);

    // [ first_config |-> [ Cyc(n lopps){ G_sec4 } ] ]:
    GroupedComputation * G_sec0 = new GroupedSequentialComputation(sec_0);

    final_module = G_sec0;
}

CompoundModule * FactoryComputationStrategy_Trivial::buildModule()
{
    return final_module;
}
