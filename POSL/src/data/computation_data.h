#pragma once

/**
 * POSL
 *
 * \file computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../packing/factory/factory_packer.h"

#include <vector>
#include <memory>
#include <string>

/*!
 * \class ComputationData computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 */
class ComputationData
{
    public:
        virtual std::shared_ptr<FactoryPacker> BuildPacker() = 0;
        virtual std::string Tag() = 0;
};
