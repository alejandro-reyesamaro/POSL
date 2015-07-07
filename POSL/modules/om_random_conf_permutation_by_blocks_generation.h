#pragma once

/**
 * POSL
 *
 * \file om_random_conf_permutation_by_blocks_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration that is a permutation by blocks
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "operation_module.h"
#include "data/solution.h"
#include "benchmarks/benchmark.h"
#include "data/seed.h"

/*!
 * \class OM_RandomConfPermutationByBlocksGeneration om_random_conf_permutation_by_blocks_generation.h
 * \brief Class to represent an Operation module to generate a random first configuration that is a permutation by blocks
 */
class OM_RandomConfPermutationByBlocksGeneration : public OperationModule
{
    public:
        //! Constructor
        OM_RandomConfPermutationByBlocksGeneration();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, but in this case is not tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return A random configuration/permutation-by-blocks
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
