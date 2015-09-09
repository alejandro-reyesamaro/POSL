#pragma once

/**
 * POSL
 *
 * \file min_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator MIN
 * \author Alejandro Reyes
 * \date 2015-08-20
 */

#include "parallel_execution_strategy.h"
#include "executer.h"
#include "min_crit_comparison.h"

/*!
 * \class MinParallelStrategy min_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator MIN
 */
class MinParallelStrategy : public ParallelExecutionStrategy
{
    public:
        MinParallelStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        Executer M1;
        Executer M2;

        std::shared_ptr<ComputationData> result1;
        std::shared_ptr<ComputationData> result2;
        std::shared_ptr<MinCritComparison> mincrit;
};
