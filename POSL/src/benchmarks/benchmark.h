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
#include "cost_strategy/solution_cost_strategy.h"

/*!
 * \class Benchmark benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 */
class Benchmark
{
    friend class PSP;
    public:        
        Benchmark(std::vector<Domain> _domains, std::shared_ptr<SolutionCostStrategy> _cost_strategy);

        int solutionCost(std::shared_ptr<Solution> sol);


        std::shared_ptr<Solution> GetSolution();
        std::vector<Domain> Domains(){ return domains; }

        virtual std::string ShowSolution(std::shared_ptr<Solution> solution) = 0;
        virtual int solutionCost(std::vector<int> configuration) = 0;

    protected:
        void UpdateSolution(std::vector<int> config);
        std::vector<Domain> domains;
        std::vector<int> configuration;
        std::shared_ptr<SolutionCostStrategy> cost_strategy;
};
