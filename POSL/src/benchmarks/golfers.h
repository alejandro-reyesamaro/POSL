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
#include "../tools/long_int.h"

/*!
 * \class Golfers golfers.h
 * \brief Class to represent an instance of a Golfers Problems
 */
class Golfers : public Benchmark
{
    public:
        Golfers(int g, int p, int w);

        int solutionCost(std::vector<int> configuration);
        std::string ShowSolution(std::shared_ptr<Solution> solution);

        int Groups(){ return groups; }
        int PlayersPerGroup(){ return players; }
        int Weeks(){ return weeks; }
        int TotalPlayers(){ return players * groups; }

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;

        // for CostOfSolution
        LongInt alldiff;
        LongInt new_partner;
        LongInt global_partnership;
        std::vector<LongInt> global_partners;
        std::vector<LongInt> group_partners;
};
