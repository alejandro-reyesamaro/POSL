#pragma once

/**
 * POSL
 *
 * \file min_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator MIN
 * \author Alejandro Reyes
 * \date 2015-08-20
 */

#include "parallel_execution_strategy.h"
#include "executer.h"
#include "min_crit_comparison.h"

/*!
 * \class MinParallelStrategy min_parallel_strategy.h
 * \brief Strategy of parallel computation for the operator MIN
 */
class MinParallelStrategy : public ParallelExecutionStrategy
{
    public:
        MinParallelStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (parallel)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) or Execute( M2 ) </pc> (depending on some minimun criteria)
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        Executer M1;
        Executer M2;

        ComputationData * result1;
        ComputationData * result2;
        MinCritComparison * mincrit;
};
