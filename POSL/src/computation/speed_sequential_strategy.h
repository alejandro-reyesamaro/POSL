#pragma once

/**
 * POSL
 *
 * \file speed_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator SPEED
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "sequential_computation_strategy.h"

/*!
 * \class SpeedSequentialStrategy speed_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator SPEED
 */
class SpeedSequentialStrategy : public SequentialComputationStrategy
{
    public:
        //! Constructor
        SpeedSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (sequential)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return The fastest module
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
};
