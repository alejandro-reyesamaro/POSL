#pragma once

/**
 * POSL
 *
 * \file golfers_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Social Golfers Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "../../tools/connection_matrix.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/random_generator.h"
#include "projectable_cost.h"

#include <algorithm>

/*!
 * \class GolfersRelativeCostStrategy golfers_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Social Golfers Problem
 */
class GolfersRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param g Number of groups.
            \param p Number of players per gruop (total of players = g * p).
            \param w Number of weeks.
         */
        GolfersRelativeCostStrategy(int g, int p, int w);

        //! From <RelativeCostStrategy>
        void initializeCostData(std::vector<int> & _configuration, int _initial_cost);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration, T_Changes _changes);

        //! From <RelativeCostStrategy>
        void updateConfiguration(std::vector<int> & new_config);

        //! From <RelativeCostStrategy>
        int costOnVariable(int variable_index);

        //! From <RelativeCostStrategy>
        int sickestVariable();

        //! (Property) From <RelativeCostStrategy>
        int currentCost() { return current_cost; }

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

        //! The current configuration.
        std::vector<int> configuration;
        //! [number of groups],[players per group],[weeks to play]
        int groups, players, weeks;
        //! Current configuration occurrences
        ConnectionMatrix cc_occurrences;
        //! Current cost
        int current_cost;
        //! A temporal vector to store the dab variables (same projected cost)
        FixedSizeVector<int> bad_variables;        
        //! Random generator to choose the <i>bad variable</i>
        RandomGenerator r_gen;
};

