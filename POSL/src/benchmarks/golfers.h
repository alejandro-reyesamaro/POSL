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

/*!
 * \class Golfers golfers.h
 * \brief Class to represent an instance of a Golfers Problems
 */
class Golfers : public Benchmark
{
    public:
        //! Constructor
        Golfers(int g, int p, int w);

        //! (override) The cost of a given Solution
        /*!
        * \param sol Solution
        * \return The cost of the Solution sol
        */
        int solutionCost(Solution * sol);

        string ShowSolution(Solution * solution);

        vector<Domain> Domains();

        //! Properties
        int Groups();
        int PlayersPerGroup();
        int Weeks();
        int TotalPlayers();

    private:
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
};
