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
        OM_FixedFirstConfiguration(shared_ptr<Benchmark> bench);

        shared_ptr<Solution> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input);

        //! From Codable
        string codeToSend();
};
