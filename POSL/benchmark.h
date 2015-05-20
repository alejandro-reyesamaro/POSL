#pragma once

/**
 * POSL
 *
 * \file benchmark.h
 * \brief Class to represent an instance of a problem
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "solution.h"

#include <vector>
#include <memory>

using namespace std;

/*!
 * \class Benchmark benchmark.h
 * \brief Class to represent an instance of a problem
 */
class Benchmark
{
    public:
        Benchmark();
        virtual int solutionCost(shared_ptr<Solution> sol) = 0;
        void UpdateSolution(shared_ptr<Solution> sol);

    //protected:
        shared_ptr<Solution> solution;
};
