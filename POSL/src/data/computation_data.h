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

using namespace std;

/*!
 * \class ComputationData computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 */
class ComputationData
{
    public:
        virtual shared_ptr<FactoryPacker> BuildPacker() = 0;
};
