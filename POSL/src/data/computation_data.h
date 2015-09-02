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

using namespace std;

/*!
 * \class ComputationData computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 */
class ComputationData
{

    public:
        //virtual ~ComputationData(){}
        virtual FactoryPacker * BuildPacker() = 0;
        /*
        virtual vector<int> pack() = 0;
        virtual int bodySize() = 0;
        virtual vector<int> body() = 0;
        */
};
