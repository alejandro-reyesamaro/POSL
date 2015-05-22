#pragma once

/**
 * POSL
 *
 * \file compound_module.h
 * \brief Class to represent a Compound Module
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

#include "data/computation_data.h"
#include "benchmarks/benchmark.h"

/*!
 * \class CompoundModule compound_module.h
 * \brief Class to represent a Compound Module
 */
class CompoundModule
{
    public:
        //! Constructor
        //CompoundModule();
        virtual ComputationData * execute(Benchmark * bench, ComputationData * input) = 0;
};
