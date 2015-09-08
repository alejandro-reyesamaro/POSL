#pragma once

/**
 * POSL
 *
 * \file union_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator Union
 * \author Alejandro Reyes
 * \date 2015-07-01
 */

#include "parallel_execution_strategy.h"
#include "executer.h"
#include "../../data/union_neighborhood.h"

/*!
 * \class UnionParallelStrategy union_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator Union
 */
class UnionParallelStrategy : public ParallelExecutionStrategy
{
    public:
        UnionParallelStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:        
        Executer M1;
        Executer M2;

        shared_ptr<Neighborhood> v1;
        shared_ptr<Neighborhood> v2;
};
