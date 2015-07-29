#pragma once

/**
 * POSL
 *
 * \file golomb_ruler.h
 * \brief Class to represent an instance of the Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2015-07-29
 */

#include "benchmark.h"

/*!
 * \class GolombRuler golomb_ruler.h
 * \brief Class to represent an instance of the Golomb Ruler Problem
 */
class GolombRuler : public Benchmark
{
    public:
        //! Constructor
        GolombRuler(int _order, int _length);

        //! (override) The cost of a given Solution
        /*!
        * \param sol Solution
        * \return The cost of the Solution sol
        */
        int solutionCost(Solution * sol);

        vector<Domain> Domains();

        //! Properties
        int Order();
        int Length();

    private:
        //! Number of marcs
        int order;
        //! Maximum distance
        int length;
};
