#pragma once

/**
 * POSL
 *
 * \file benchmark.h
 * \brief Class to represent an instance of a problem
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "data/solution.h"

#include <vector>

using namespace std;

/*!
 * \class Benchmark benchmark.h
 * \brief Class to represent an instance of a problem
 */
class Benchmark
{
    public:
        Benchmark();
        virtual int solutionCost(Solution * sol) = 0;
        void UpdateSolution(Solution * sol);

    //protected:
        Solution * solution;
};
