#pragma once

/**
 * POSL
 *
 * \file n_queens_default_show_strategy.h
 * \brief Class to represent the way N-Queens problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class NQueensDefaultShowStrategy n_queens_default_show_strategy.h
 * \brief Class to represent the way N-Queens problem shows its result (solution)
 */
class NQueensDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order: number of queens in a table of n x n.
         */
        NQueensDefaultShowStrategy(int n);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! number of queens in a table of N x N.
        int N;
};
