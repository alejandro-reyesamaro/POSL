#pragma once

/**
 * POSL
 *
 * \file not_implemented_parallel_strategy.h
 * \brief Class to represent a not supported strategy (in parallel)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "parallel_execution_strategy.h"

/*!
 * \class NotImplementedParallelStrategy not_implemented_parallel_strategy.h
 * \brief Class to represent a not supported strategy (in parallel)
 */
class NotImplementedParallelStrategy : public ParallelExecutionStrategy
{
    public:
        NotImplementedParallelStrategy();

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP>, std::shared_ptr<ComputationData>);
};
