#pragma once

/**
 * POSL
 *
 * \file all_intervals_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of All-Intervals Series Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "all_intervals_cost_structure.h"

#include <memory>

/*!
 * \class AllIntervalsDanielCostStrategy all_intervals_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Costas Array Problem
 */
class AllIntervalsDanielCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        AllIntervalsDanielCostStrategy(int n);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! All-Intervals Series cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<AllIntervalsCostStructure> cost_str;
};
