#pragma once

/**
 * POSL
 *
 * \file golomb_ruler_relative_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"
#include "golomb_measures_struct.h"

#include <vector>
#include <memory>

/*!
 * \class GolombRulerRelativeCostStructure golomb_ruler_relative_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Golomb Ruler Problem
 */
class GolombRulerRelativeCostStructure : public ProjectableCost
{
    public:
        //! Default constructor.
        /*!
            \param _order Problem order: number of marks.
            \param _length Maximal measure (final mark).
         */
        GolombRulerRelativeCostStructure(int _order, int _length);

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
        /*! Method to update the informations about the measures
         */
        /*!
            \param configuration_before_chanche The current configuration before change.
            \param new_pos The position of the new change
            \param new_value The value of the new change
            \param measures A vector with the global measures
            \param updating Whether the information is updated or not
         */
        void update_measures(std::vector<int> & configuration_before_chanche,
                             int new_pos,
                             int new_value,
                             std::vector<int> & measures,
                             bool updating);

        //! Auxiliar container for the current configuration
        std::vector<int> aux_configuration;
        //! A global counter of the measures
        std::vector<int> measure_counters;
        //! Auxiliar container for the global counter of the measures
        std::vector<int> aux_measure_counters;
        //! A counter of the measures for each variable
        std::shared_ptr<GolombMeasuresStruct> measure_per_variable;
};
