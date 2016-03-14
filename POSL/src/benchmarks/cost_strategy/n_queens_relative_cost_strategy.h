#pragma once

#include "relative_cost_strategy.h"
#include "n_queens_cost_structure.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/random_generator.h"

#include <memory>

class NQueensRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        NQueensRelativeCostStrategy(int n);

        void initializeCostData(std::vector<int> & _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> & _configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes change);
        void updateConfiguration(std::vector<int> & new_config);
        int currentCost() { return nq_str->CurrentCost; }

        int costOnVariable(int i);
        int sickestVariable();

    private:
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);

        int N;
        std::shared_ptr<NQueensCostStructure> nq_str;
        FixedSizeVector<int> bad_variables;
        RandomGenerator r_gen;
};

