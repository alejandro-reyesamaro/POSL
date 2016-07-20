#pragma once

/**
 * POSL
 *
 * \file n_queens_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of N-Queens Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "n_queens_cost_structure.h"

#include <memory>

/*!
 * \class NQueensDanielCostStrategy n_queens_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of N-Queens Problem
 */
class NQueensDanielCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order: number of queens in a table of n x n.
         */
        NQueensDanielCostStrategy(int n);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! number of queens in a table of N x N.
        int N;

        //! N-Queens cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<NQueensCostStructure> nq_str;
};
