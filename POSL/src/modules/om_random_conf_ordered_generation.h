#pragma once

#include "aom_first_configuration_generation.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/seed.h"


class OM_RandomConfOrderedGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        //! Constructor
        OM_RandomConfOrderedGeneration();

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, but in this case is not tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return A random configuration/permutation-by-blocks
        */
        Solution * spcf_execute(PSP * psp, Solution * input);

        //! From Codable
        string codeToSend();
};
