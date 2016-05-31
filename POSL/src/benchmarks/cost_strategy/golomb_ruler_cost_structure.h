#pragma once

/**
 * POSL
 *
 * \file golomb_ruler_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include <vector>
#include <list>
#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"

/*!
 * \class GolombRulerCostStructure golomb_ruler_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Golomb Ruler Problem
 */
class GolombRulerCostStructure : public ProjectableCost
{
    public:
        //! Default constructor.
        /*!
            \param _order Problem order: number of marks.
            \param _length Maximal measure (final mark).
         */
        GolombRulerCostStructure(int _order, int _length);

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

        //! Initialize the information related to the cost.
        /*!
            \param _configuration A configuration (solution).
         */
        void init(std::vector<int> config);

        //! From <ProjectableCost>
        int costOnVariable(int index);

        //! Performs a <i>reset</i> w.r.t the current configuration.
        /*!
            \return A configuration <i>reseted</i>.
         */
        void reset();

        //! (Field) Number of marks.
        int Order;
        //! (Field) Final mark.
        int Length;
        //! (Field) The current cost
        int CurrentCost;
        //! (Field) The current configuration
        std::vector<int> Configuration;

    private:
        //! Function to compute and initialize the cost.
        /*!
            \param config A given configuration.
            \return The current (computed) cost.
         */
        int cost(std::vector<int> & config);

        //! A global counter of the measures
        std::vector<int> measure_counters;
        //! A counter of the measures for each variable
        std::vector<std::list<int>> measure_per_variable;




        //std::vector<std::list<int>> measures_intervenants;
        //std::vector<std::list<int>> measures_intervenants_index;
        //std::vector<std::list<int>> negative_measures_intervenants;
        //std::vector<int> variables_in_negative_measures;
        //std::vector<int> aux_new_config;
};
