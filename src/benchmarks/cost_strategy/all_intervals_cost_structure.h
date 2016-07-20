#pragma once

/**
 * POSL
 *
 * \file all_interval_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of All-Interval Series Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"
#include "../../tools/randomizer.h"

#include <vector>

/*!
 * \class AllIntervalsCostStructure all_interval_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of All-Interval Series Problem
 */
class AllIntervalsCostStructure : public ProjectableCost
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        AllIntervalsCostStructure(int _n);

        /*! Computes the cost of a configuration relative to the current configuration.
         *  User must specify if the information will be updated or not
         */
        /*!
            \param new_config A configuration (solution).
            \param . The performed changes w.r.t the current configuration
            \param updating Whether the information is updated or not
            \return Cost of the given configuration.
         */
        int relative_cost(std::vector<int> & new_config, T_Changes, bool updating);

        //! Initialize the information related to the cost.
        /*!
            \param _configuration A configuration (solution).
         */
        void init(std::vector<int> _configuration);

        //! From <ProjectableCost>
        int costOnVariable(int index);

        //! Returns the index of the variable with the highest cost if swaped.
        /*!
            \return Index of the worst variable.
         */
        int worst_variable();

        //! Performs a <i>reset</i> w.r.t the current configuration.
        /*!
            \return A configuration <i>reseted</i>.
         */
        void reset();

        //! (Field) All-Intervals Series Problem Order.
        int N;
        //! (Field) The current cost
        int CurrentCost;
        //! (Field) The current configuration
        std::vector<int> Configuration;

    private:
        //! The number of occurrences
        std::vector<int> nb_occ;
        //! The number of occurrences (auxiliar)
        std::vector<int> nb_occ_aux;
        //! A random generaor to perform <i>resets</i>
        std::shared_ptr<Randomizer> rand;
};
