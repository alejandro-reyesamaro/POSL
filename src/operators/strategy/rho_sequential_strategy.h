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
        RhoSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2, float _rho);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;
        float rho;
        std::shared_ptr<ComputationData> output1;
        std::shared_ptr<ComputationData> output2;
};
