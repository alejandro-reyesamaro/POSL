#pragma once

/**
 * POSL
 *
 * \file operator.h
 * \brief Class to represent an operation between modules
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "../modules/compound_module.h"
#include "strategy/sequential_execution_strategy.h"
#include "strategy/parallel_execution_strategy.h"
#include "../packing/codable.h"

#include <vector>

/*!
 * \class Operator operator.h
 * \brief Class to represent an operation between modules
 */
class Operator : public Codable, public Connectable
{
    public:
        Operator(std::shared_ptr<SequentialExecutionStrategy> _seq_strategy,
                 std::shared_ptr<ParallelExecutionStrategy> _para_strategy);

        std::shared_ptr<ComputationData> evaluateSequentially(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        std::shared_ptr<ComputationData> evaluateInParallel(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    protected:
        std::shared_ptr<SequentialExecutionStrategy> seq_strategy;
        std::shared_ptr<ParallelExecutionStrategy> para_strategy;
};
