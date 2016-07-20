#pragma once

/**
 * POSL
 *
 * \file speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "parallel_execution_strategy.h"
#include "executer.h"

/*!
 * \class SpeedParallelStrategy speed_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator SPEED
 */
class SpeedParallelStrategy : public ParallelExecutionStrategy
{
    public:
        //! Constructor
        SpeedParallelStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP>, std::shared_ptr<ComputationData>);

    private:
        Executer M1;
        Executer M2;
};
