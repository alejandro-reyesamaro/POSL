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
        shared_ptr<CompoundModule> uncodeCompoundModule(string code, shared_ptr<Benchmark> bench);

    private:
        shared_ptr<CyclicOperator> uncodeCyclicOperator(string code, shared_ptr<Benchmark> bench);
        shared_ptr<ConditionalOperator> uncodeConditionalOperator(string code, shared_ptr<Benchmark> bench);
        shared_ptr<RhoOperator> uncodeRhoOperator(string code, shared_ptr<Benchmark> bench);
        shared_ptr<BinaryOperator> uncodeBinaryOperator(string code, shared_ptr<Benchmark> bench);
        shared_ptr<Operator> uncodeOperator(string code, shared_ptr<Benchmark> bench);
        shared_ptr<GroupedSequentialComputation> uncodeGroupedSequentialComputation(string code, shared_ptr<Benchmark> bench);
        shared_ptr<GroupedParallelComputation> uncodeGroupedParallelComputation(string code, shared_ptr<Benchmark> bench);
        shared_ptr<OperationModule> uncodeOperationModule(string code, shared_ptr<Benchmark> bench);
        shared_ptr<BooleanExpression> uncodeBoolExpression(string code);
};
