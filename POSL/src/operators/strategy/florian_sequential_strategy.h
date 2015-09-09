#pragma once

/**
 * POSL
 *
 * \file florian_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator FLORIAN
 * \author Alejandro Reyes
 * \date 2015-08-27
 */

#include "sequential_execution_strategy.h"

/*!
 * \class FlorianSequentialStrategy florian_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator FLORIAN
 */
class FlorianSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        FlorianSequentialStrategy(std::shared_ptr<CompoundModule> _M1);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

    private:
        std::shared_ptr<CompoundModule> M1;

        std::shared_ptr<Solution> best_solution;
        std::shared_ptr<Solution> temp_solution;
};
