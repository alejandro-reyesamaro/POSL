#pragma once

/**
 * POSL
 *
 * \file relative_cost_strategy.h
 * \brief Interface to represent a relative solution cost strategy
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "../../tools/t_changes.h"
#include "../../data/seed.h"

#include <vector>

/*!
 * \class RelativeCostStrategy relative_cost_strategy.h
 * \brief Interface to represent a relative solution cost strategy
 */
class RelativeCostStrategy
{
    public:
        //! Computes the cost of a configuration relative to the current configuration.
        /*!
            \param _configuration A configuration (solution).
            \return Cost of the given configuration.
         */
        virtual int relativeSolutionCost(std::vector<int> & _configuration) = 0;

        //! Initialize the information related to the cost.
        /*!
            \param _configuration A configuration (solution).
            \param _initial_cost The initial cost of the configuration.
         */
        virtual void initializeCostData(std::vector<int> & _configuration, int _initial_cost) = 0;

        //! Computes the cost of a configuration relative to the current configuration.
        /*!
            \param _configuration A configuration (solution).
            \param _change The performed changes w.r.t the current configuration
            \return Cost of the given configuration.
         */
        virtual int relativeSolutionCost(std::vector<int> & _configuration, T_Changes _change) = 0;

        //! Updates the current configuration.
        /*!
            \param new_config A configuration (solution).
         */
        virtual void updateConfiguration(std::vector<int> & new_config) = 0;

        //! Returns the current cost.
        /*!
            \return Current cost.
         */
        virtual int currentCost() = 0;

        //! Computes the projected cost of a variable.
        /*!
            \param variable_index Index of a variable.
            \return The projected cost of the variable with index <i>variable_index</i>.
         */
        virtual int costOnVariable(int variable_index) = 0;

        //! Returns the variable with the highest projected cost.
        /*!
            \return The projected cost of the variable with highest projected cost.
         */
        virtual int sickestVariable() = 0;
};
