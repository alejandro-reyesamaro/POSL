#pragma once

/**
 * POSL
 *
 * \file solver.h
 * \brief Class to represent a solver
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "modules/compound_module.h"
#include "benchmarks/benchmark.h"
#include "factory_compound_module.h"

using namespace std;

/*!
 * \class Solver solver.h
 * \brief Class to represent a solver
 */
class Solver
{
    public:
        Solver(FactoryCompoundModule * facCM, Benchmark * bench);

    private:
        //CompoundModule cm;
        Benchmark * problem;
};
