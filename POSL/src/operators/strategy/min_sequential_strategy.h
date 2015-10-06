#pragma once

/**
 * POSL
 *
 * \file min_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator MIN
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "sequential_execution_strategy.h"
#include "min_crit_comparison.h"

/*!
 * \class MinSequentialStrategy min_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator MIN
 */
class MinSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        MinSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;

        std::shared_ptr<ComputationData> result1;
        std::shared_ptr<ComputationData> result2;
        std::shared_ptr<MinCritComparison> mincrit;
};
