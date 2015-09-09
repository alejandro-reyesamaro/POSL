#pragma once

/**
 * POSL
 *
 * \file union_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Union
 * \author Alejandro Reyes
 * \date 2015-07-01
 */

#include "sequential_execution_strategy.h"
#include "../../data/union_neighborhood.h"

#include <random>
#include <chrono>

/*!
 * \class UnionSequentialStrategy union_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Union
 */
class UnionSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        UnionSequentialStrategy(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<CompoundModule> M2;

        std::shared_ptr<Neighborhood> v1;
        std::shared_ptr<Neighborhood> v2;
};
