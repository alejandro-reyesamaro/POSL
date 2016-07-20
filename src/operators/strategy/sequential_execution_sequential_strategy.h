#pragma once

/**
 * POSL
 *
 * \file sequential_execution_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Sequential Execution
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "sequential_execution_strategy.h"

/*!
 * \class SequentialExecutionSequentialStrategy sequential_execution_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Sequential Execution
 */
class SequentialExecutionSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        SequentialExecutionSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:        
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;
};
