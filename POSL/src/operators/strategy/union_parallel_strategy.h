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
        UnionParallelStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (parallel)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) U Execute( M2 ) </pc> (not yet optimized)
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:        
        Executer M1;
        Executer M2;

        Neighborhood * v1;
        Neighborhood * v2;
};
