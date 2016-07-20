#pragma once

/**
 * POSL
 *
 * \file golomb_ruler_max_possible_distances_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "golomb_ruler_cost_structure.h"
#include "golomb_ruler_relative_cost_structure.h"

#include <memory>

/*!
 * \class GolombRulerMaxPossibleDistancesCostStrategy golomb_ruler_max_possible_distances_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Golomb Ruler Problem
 */
class GolombRulerMaxPossibleDistancesCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _order Problem order: number of marks.
            \param _length Maximal measure (final mark).
         */
        GolombRulerMaxPossibleDistancesCostStrategy(int _order, int _length);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! Golomb Ruler cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        //std::shared_ptr<GolombRulerRelativeCostStructure> cost_structure;
        std::shared_ptr<GolombRulerCostStructure> cost_structure;
};
