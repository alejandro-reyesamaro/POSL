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
#include "../tools/t_changes.h"
#include "cost_strategy/solution_cost_strategy.h"
#include "show_strategy/show_strategy.h"
#include "cost_strategy/relative_cost_strategy.h"
#include "../tools/randomizer.h"

/*!
 * \class Benchmark benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 */
class Benchmark
{
    friend class PSP;
    public:
        Benchmark(std::vector<Domain> _domains,
                  std::shared_ptr<SolutionCostStrategy> _cost_strategy,
                  std::shared_ptr<RelativeCostStrategy> _relative_cost_strategy,
                  std::shared_ptr<ShowStrategy> _show_strategy);

        int solutionCost(std::shared_ptr<Solution> sol);
        int solutionCost(std::vector<int> configuration);        
        int relativeSolutionCost(std::vector<int> configuration);
        int relativeSolutionCost(std::vector<int> new_config, T_Changes changes);
        int currentCost();

        std::shared_ptr<Solution> GetSolution();
        std::string ShowSolution(std::shared_ptr<Solution> solution);

        //! Projected Cost (AS)
        int costOnVariable(int index);
        int sickestVariable();

        std::vector<Domain> Domains(){ return domains; }

        virtual std::string showInstance() = 0;

    protected:
        void UpdateSolution(std::vector<int> config);
        void InitializeCostData(std::vector<int> config);
        std::vector<Domain> domains;
        std::vector<int> configuration;

        //! STRATEGIES
        std::shared_ptr<SolutionCostStrategy> cost_strategy;
        std::shared_ptr<RelativeCostStrategy> relative_cost_strategy;
        std::shared_ptr<ShowStrategy> show_strategy;
};
