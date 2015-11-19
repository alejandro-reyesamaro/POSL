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

#define OM_FIXED_FIRST_CONFIGURATION_TOK "OM_S.Fix"

/*!
 * \class OM_FixedFirstConfiguration om_fixed_first_conf_generation.h
 * \brief Class to represent an Operation Module to give a fixed first configuration
 */
class OM_FixedFirstConfiguration : public AOM_FirstConfigurationGeneration
{
    public:
        OM_FixedFirstConfiguration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();
};
