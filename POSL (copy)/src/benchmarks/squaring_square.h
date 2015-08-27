#pragma once

/**
 * POSL
 *
 * \file squaring_square.h
 * \brief Class to represent an instance of a Squaring Square Problems
 * \author Alejandro Reyes
 * \date 2015-07-29
 */

#include "benchmark.h"

/*!
 * \class SquaringSquare squaring_square.h
 * \brief Class to represent an instance of a Squaring Square Problems
 */
class SquaringSquare : public Benchmark
{
    public:
        //! Constructor
        SquaringSquare(int _size, vector<int> _squares);

        //! (override) The cost of a given Solution
        /*!
        * \param sol Solution
        * \return The cost of the Solution sol
        */
        int solutionCost(Solution * sol);

        string ShowSolution(Solution * solution);

        vector<Domain> Domains();

        //! Properties
        int Size();
        int SquareAt(int pos);

    private:
        //! Size of the big square
        int size;
        //! Sizes of the squares to put into the big one
        vector<int> squares;
};
