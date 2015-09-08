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

/*!
 * \class CompoundModule compound_module.h
 * \brief Class to represent a Compound Module
 */
class CompoundModule : public Codable
{
    public:
        virtual shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input) = 0;
};
