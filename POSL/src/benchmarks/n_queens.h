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

        int Order(){ return N; }

        int solutionCost(std::vector<int> configuration);
        std::string ShowSolution(std::shared_ptr<Solution> solution);

    private:
        //! order
        int N;
};
