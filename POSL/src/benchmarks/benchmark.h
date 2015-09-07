#pragma once

/**
 * POSL
 *
 * \file benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "../data/solution.h"

#include <vector>

using namespace std;

/*!
 * \class Benchmark benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 */
class Benchmark
{
    public:
        Benchmark(vector<Domain> _domains);

        int solutionCost(Solution * sol);        
        void UpdateSolution(Solution * sol);

        Solution * GetSolution(){ return solution; }
        vector<Domain> Domains(){ return domains; }

        virtual string ShowSolution(Solution * solution) = 0;
        virtual int solutionCost(vector<int> configuration) = 0;

    protected:
        Solution * solution;
        vector<Domain> domains;
};
