#pragma once

/**
 * POSL
 *
 * \file speed_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator SPEED
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "sequential_execution_strategy.h"
#include "../../tools/chronometer.h"

/*!
 * \class SpeedSequentialStrategy speed_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator SPEED
 */
class SpeedSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        SpeedSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<CompoundModule> M2;

        shared_ptr<Chronometer> chro;
        shared_ptr<ComputationData> result1;
        shared_ptr<ComputationData> result2;
};
