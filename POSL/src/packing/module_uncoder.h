#pragma once

#include "../modules/compound_module.h"

#include "../modules/grouped_sequential_computation.h"
#include "../modules/grouped_parallel_computation.h"
#include "../modules/operation_module.h"

#include "../operators/cyclic_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/rho_operator.h"

class ModuleUncoder
{
    public:
        ModuleUncoder();
        CompoundModule * uncodeCompoundModule(string code, Benchmark * bench);

    private:
        CyclicOperator * uncodeCyclicOperator(string code, Benchmark * bench);
        ConditionalOperator * uncodeConditionalOperator(string code, Benchmark * bench);
        RhoOperator * uncodeRhoOperator(string code, Benchmark * bench);
        BinaryOperator * uncodeBinaryOperator(string code, Benchmark * bench);
        Operator * uncodeOperator(string code, Benchmark * bench);
        GroupedSequentialComputation * uncodeGroupedSequentialComputation(string code, Benchmark * bench);
        GroupedParallelComputation * uncodeGroupedParallelComputation(string code, Benchmark * bench);
        OperationModule * uncodeOperationModule(string code, Benchmark * bench);
        BooleanExpression * uncodeBoolExpression(string code);
};
