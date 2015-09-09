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
        std::shared_ptr<CompoundModule> uncodeCompoundModule(std::string code, std::shared_ptr<Benchmark> bench);

    private:
        std::shared_ptr<CyclicOperator> uncodeCyclicOperator(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<ConditionalOperator> uncodeConditionalOperator(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<RhoOperator> uncodeRhoOperator(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<BinaryOperator> uncodeBinaryOperator(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<Operator> uncodeOperator(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<GroupedSequentialComputation> uncodeGroupedSequentialComputation(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<GroupedParallelComputation> uncodeGroupedParallelComputation(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<OperationModule> uncodeOperationModule(std::string code, std::shared_ptr<Benchmark> bench);
        std::shared_ptr<BooleanExpression> uncodeBoolExpression(std::string code);
};
