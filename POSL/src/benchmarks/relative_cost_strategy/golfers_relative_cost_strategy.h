#pragma once

#include "relative_cost_strategy.h"

struct Occurrences
{
    Occurrences(int n) : players(n, 0){}
    int GetValue(int pos){ return players[pos]; }
    void SetValue(int pos, int value){ players[pos] = value; }
    void IncreaseValue(int pos){ players[pos] ++; }
    void DecreaseValue(int pos){ players[pos] --; }
    std::vector<int> players;
};

class GolfersRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        GolfersRelativeCostStrategy(int g, int p, int w);

        void initializeCostData(std::vector<int> _configuration, int initial_cost);
        int relativeSolutionCost(std::vector<int> _configuration);
        int relativeSolutionCost(std::vector<int> new_config, T_Changes change);
        void updateConfiguration(T_Changes change);

    private:
        std::vector<int> configuration;
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Current configuration occurrences
        std::vector<Occurrences> cc_occurrences;
        int current_cost;
};

