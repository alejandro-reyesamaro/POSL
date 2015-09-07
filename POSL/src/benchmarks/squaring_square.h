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
        SquaringSquare(int _size, vector<int> _squares);

        int solutionCost(vector<int> configuration);
        string ShowSolution(shared_ptr<Solution> solution);

        int Size(){ return size; }
        int SquareAt(int pos){ return (pos >= 0 && pos < size)? squares[pos] : -1; }

    private:
        //! [Size of the big square]
        int size;
        //! [Sizes of the squares to put into the big one]
        vector<int> squares;
};
