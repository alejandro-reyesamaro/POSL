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
//#include "../tools/long_int.h"

/*!
 * \class GolombRuler golomb_ruler.h
 * \brief Class to represent an instance of the Golomb Ruler Problem
 */
class GolombRuler : public Benchmark
{
    public:
        GolombRuler(int _order, int _length);

        int solutionCost(std::vector<int> configuration);
        std::string ShowSolution(std::shared_ptr<Solution> solution);

        int Order(){ return order; }
        int Length(){ return length; }

    private:
        //! [Number of marcs], [Maximum distance]
        int order, length;
};
