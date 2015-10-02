#pragma once

/**
 * POSL
 *
 * \file golfers.h
 * \brief Class to represent an instance of a Golfers Problems
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "benchmark.h"
//#include "../tools/long_int.h"

/*!
 * \class Golfers golfers.h
 * \brief Class to represent an instance of a Golfers Problems
 */
class Golfers : public Benchmark
{
    public:
        Golfers(int g, int p, int w);

        //int relativeSolutionCost(std::vector<int> _configuration);
        //void initializeCostData();

        int Groups(){ return groups; }
        int PlayersPerGroup(){ return players; }
        int Weeks(){ return weeks; }
        int TotalPlayers(){ return players * groups; }

        std::string showInstance();

    private:
        //int relativeSolutionCost(T_Changes change);

        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Current configuration occurrences
        //std::vector<Occurrences> cc_occurrences;
        //int current_cost;
};
