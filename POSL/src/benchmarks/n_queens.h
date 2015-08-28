#pragma once

/**
 * POSL
 *
 * \file n_queens.h
 * \brief Class to represent an instance of an N-Queens Problem
 * \author Alejandro Reyes
 * \date 2015-08-28
 */

#include "benchmark.h"

/*!
 * \class NQueens n_queens.h
 * \brief Class to represent an instance of an N-Queens Problem
 */
class NQueens : public Benchmark
{
    public:
        //! Constructor
        NQueens(int n);

        //! (override) The cost of a given Solution
        /*!
        * \param sol Solution
        * \return The cost of the Solution sol
        */
        int solutionCost(Solution * sol);

        string ShowSolution(Solution * solution);

        vector<Domain> Domains();

        //! Properties
        int Order();

    private:
        //! order
        int N;
};
