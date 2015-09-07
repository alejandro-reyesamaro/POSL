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
#include <memory>

using namespace std;

/*!
 * \class Benchmark benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 */
class Benchmark
{
    public:
        Benchmark(vector<Domain> _domains);

        int solutionCost(shared_ptr<Solution> sol);
        void UpdateSolution(shared_ptr<Solution> sol);

        shared_ptr<Solution> GetSolution(){ return solution; }
        vector<Domain> Domains(){ return domains; }

        virtual string ShowSolution(shared_ptr<Solution> solution) = 0;
        virtual int solutionCost(vector<int> configuration) = 0;

    protected:
        shared_ptr<Solution> solution;
        vector<Domain> domains;
};
