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
#include "../../tools/randomizer.h"

#include <random>
#include <chrono>

/*!
 * \class RhoSequentialStrategy rho_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Rho
 */
class RhoSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        RhoSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, float _rho);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<CompoundModule> M2;
        float rho;
        Randomizer rand;

        shared_ptr<ComputationData> output1;
        shared_ptr<ComputationData> output2;
};
