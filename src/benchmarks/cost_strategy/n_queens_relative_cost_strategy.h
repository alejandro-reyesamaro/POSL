#pragma once

/**
 * POSL
 *
 * \file n_queens_relative_cost_ctrategy.h
 * \brief Class to represent the relative cost stratategy of N-Queens Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "n_queens_cost_structure.h"
#include "sickest_variable_strategy.h"

#include <memory>

/*!
 * \class NQueensRelativeCostStrategy n_queens_relative_cost_ctrategy.h
 * \brief Class to represent the relative cost stratategy of N-Queens Problem
 */
class NQueensRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order: number of queens in a table of n x n.
         */
        NQueensRelativeCostStrategy(int n);

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
        int currentCost() { return nq_str->CurrentCost; }

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

        //! N-Queens cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<NQueensCostStructure> nq_str;

        //! Strategy to compute the most troubled variable.
        /*!
            In this problem, the strategy is by default: select the index of a variable
            with the highest projected cost, using the function <b>sickestVariable()</b>
        */
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};

