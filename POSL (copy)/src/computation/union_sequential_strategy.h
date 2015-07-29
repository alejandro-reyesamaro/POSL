#pragma once

/**
 * POSL
 *
 * \file union_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Union
 * \author Alejandro Reyes
 * \date 2015-07-01
 */

#include "sequential_computation_strategy.h"

#include <random>
#include <chrono>

/*!
 * \class UnionSequentialStrategy union_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Union
 */
class UnionSequentialStrategy : public SequentialComputationStrategy
{
    public:
        //! Constructor
        UnionSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (sequential)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) U Execute( M2 ) </pc> (not yet optimized)
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
};
