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
        NQueens(int n);

        int solutionCost(vector<int> configuration);
        string ShowSolution(shared_ptr<Solution> solution);

        //! Properties
        int Order();

    private:
        //! order
        int N;
        vector<int> err_d1;
        vector<int> err_d2;
        vector<unsigned int> flags;
};
