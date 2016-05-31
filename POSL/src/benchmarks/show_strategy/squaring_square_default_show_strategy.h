#pragma once

/**
 * POSL
 *
 * \file squaring_square_default_show_strategy.h
 * \brief Class to represent the way Squaring the Square problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class SquaringSquareDefaultShowStrategy squaring_square_default_show_strategy.h
 * \brief Class to represent the way Squaring the Square problem shows its result (solution)
 */
class SquaringSquareDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _n_squares number of squares.
         */
        SquaringSquareDefaultShowStrategy(int _n_squares);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! [number of square]
        int n_squares;
};
