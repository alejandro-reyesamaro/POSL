#pragma once

/**
 * POSL
 *
 * \file subsum_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Subsum Sequence Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "subsum_cost_structure.h"
#include "sickest_variable_strategy.h"

/*!
 * \class SubsumRelativeCostStrategy subsum_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Subsum Sequence Problem
 */
class SubsumRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param values The array with the values.
            \param subsum Subsum to find.
            \param n The number of values adding up to <b>subsum</b>.
         */
        SubsumRelativeCostStrategy(std::vector<int> values, int subsum, int n);

        //! From <RelativeCostStrategy>
        void initializeCostData(std::vector<int> & _configuration, int _initial_cost);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration, T_Changes _change);

        //! From <RelativeCostStrategy>
        void updateConfiguration(std::vector<int> & new_config);

        //! From <RelativeCostStrategy>
        int costOnVariable(int variable_index);

        //! From <RelativeCostStrategy>
        int sickestVariable();

        //! (Property) From <RelativeCostStrategy>
        int currentCost();

    private:
        /*! Computes the cost of a configuration relative to the current configuration.
         *  User must specify if the information will be updated or not
         */
        /*!
            \param new_config A configuration (solution).
            \param change The performed changes w.r.t the current configuration
            \param updating Whether the information is updated or not
            \return Cost of the given configuration.
         */
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);

        //! Subsum Sequence cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<SubsumCostStructure> cost_structure;

        //! Strategy to compute the most troubled variable.
        /*!
            In this problem, the strategy is by default: select the index of a variable
            with the highest projected cost, using the function <b>sickestVariable()</b>
        */
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
