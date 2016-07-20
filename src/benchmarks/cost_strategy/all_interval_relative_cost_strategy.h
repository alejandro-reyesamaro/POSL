#pragma once

/**
 * POSL
 *
 * \file all_interval_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of All-Interval Series Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "all_intervals_cost_structure.h"
#include "sickest_variable_strategy.h"

#include <memory>

/*!
 * \class AllIntervalRelativeCostStrategy all_interval_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of All-Interval Series Problem
 */
class AllIntervalRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        AllIntervalRelativeCostStrategy(int n);

        //! From <RelativeCostStrategy>
        void initializeCostData(vector<int> & _configuration, int _initial_cost);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(vector<int> & _configuration);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & new_config, T_Changes);

        //! From <RelativeCostStrategy>
        void updateConfiguration(vector<int> & new_config);

        //! From <RelativeCostStrategy>
        int costOnVariable(int variable_index);

        //! From <RelativeCostStrategy>
        int sickestVariable();

        //! Performs a <i>reset</i> w.r.t the current configuration.
        /*!
            \return A configuration <i>reseted</i>.
         */
        std::vector<int> Reset();

        //! (Property) From <RelativeCostStrategy>
        int currentCost() { return cost_str->CurrentCost; }


    private:

        //! All-Intervals Series cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<AllIntervalsCostStructure> cost_str;

        //! Strategy to compute the most troubled variable.
        /*!
            In this problem, the strategy is by default: select the index of a variable
            with the highest projected cost, using the function <b>sickestVariable()</b>
        */
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
