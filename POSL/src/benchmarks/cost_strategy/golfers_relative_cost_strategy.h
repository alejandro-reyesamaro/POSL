#pragma once

#include "relative_cost_strategy.h"
#include "../../tools/connection_matrix.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/random_generator.h"
#include "projectable_cost.h"

#include <algorithm>

struct Occurrences
{
    Occurrences(int n) : players(n, 0){}
    int GetValue(int pos){ return players[pos]; }
    void SetValue(int pos, int value){ players[pos] = value; }
    void IncreaseValue(int pos){ players[pos] ++; }
    void DecreaseValue(int pos){ players[pos] = std::min(0, players[pos] - 1); }
    std::vector<int> players;
};

class GolfersRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        GolfersRelativeCostStrategy(int g, int p, int w);

        void initializeCostData(std::vector<int> & _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> & _configuration);
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes changes);
        void updateConfiguration(std::vector<int> & new_config);
        int currentCost() { return current_cost; }

        int costOnVariable(int variable_index);
        int sickestVariable();

    private:
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);

        std::vector<int> configuration;
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Current configuration occurrences
        ConnectionMatrix cc_occurrences;
        int current_cost;
        FixedSizeVector<int> bad_variables;
        RandomGenerator r_gen;
};

