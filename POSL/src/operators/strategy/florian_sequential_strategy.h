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
        FlorianSequentialStrategy(shared_ptr<CompoundModule> _M1);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;

        shared_ptr<Solution> best_solution;
        shared_ptr<Solution> temp_solution;
};
