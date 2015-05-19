#pragma once

/**
 * POSL
 *
 * \file solver.h
 * \brief Class to represent a solver
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "compound_module.h"
#include "benchmark.h"
#include "factory_compound_module.h"

#include <memory>

using namespace std;

/*!
 * \class Solver solver.h
 * \brief Class to represent a solver
 */
class Solver
{
    public:
        Solver(shared_ptr<FactoryCompoundModule> facCM, shared_ptr<Benchmark> bench);

    private:
        CompoundModule cm;
        shared_ptr<Benchmark> problem;
};
