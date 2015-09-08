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
        MinSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<CompoundModule> M2;

        shared_ptr<ComputationData> result1;
        shared_ptr<ComputationData> result2;
        shared_ptr<MinCritComparison> mincrit;
};
