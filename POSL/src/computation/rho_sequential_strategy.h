#pragma once

/**
 * POSL
 *
 * \file rho_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "sequential_execution_strategy.h"
#include "../tools/randomizer.h"

#include <random>
#include <chrono>

/*!
 * \class RhoSequentialStrategy rho_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 */
class RhoSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        //! Constructor
        RhoSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2, float _rho);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) or Execute( M2 ) </pc> (depending on rho)
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
        //! Probability
        float rho;

        Randomizer rand;
};
