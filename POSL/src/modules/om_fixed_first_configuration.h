#pragma once

/**
 * POSL
 *
 * \file om_fixed_first_conf_generation.h
 * \brief Class to represent an Operation Module to give a fixed first configuration
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "aom_first_configuration_generation.h"

/*!
 * \class OM_FixedFirstConfiguration om_fixed_first_conf_generation.h
 * \brief Class to represent an Operation Module to give a fixed first configuration
 */
class OM_FixedFirstConfiguration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_FixedFirstConfiguration(Benchmark * bench);

        //! Execute the O.M.
        /*!
        * \brief The input is a configuration, it will be tacken into account
        * \param psp The Problem Search Process
        * \param input Input (configuration)
        * \return The same configuration passed in the parameters
        */
        Solution * spcf_execute(PSP * psp, Solution * input);

        //! From Codable
        string codeToSend();
};
