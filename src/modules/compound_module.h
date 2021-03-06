#pragma once

/**
 * POSL
 *
 * \file compound_module.h
 * \brief Class to represent a Compound Module
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

#include "../data/computation_data.h"
#include "../solver/psp.h"
#include "../packing/codable.h"
#include "../connections/connectable.h"

/*!
 * \class CompoundModule compound_module.h
 * \brief Class to represent a Compound Module
 */
class CompoundModule : public Codable, public Connectable
{
    public:
        virtual std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input) = 0;
        virtual std::string Tag() = 0;
};
