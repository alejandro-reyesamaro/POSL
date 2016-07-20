#pragma once

/**
 * POSL
 *
 * \file om_simulated_annealing_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 * \author Alejandro Reyes
 * \date 2015-07-02
 */

#include "aom_decision_function.h"

//#include <random>

/*!
 * \class OM_SimulatedAnnealingDecition om_simulated_annealing_decition.h
 * \brief Class to represent an Operation Module to decide if a configuration is keeped to the next iteration
 */
class OM_SimulatedAnnealingDecision : public AOM_DecisionFunction
{
    public:
        ///
        /// \brief OM_SimulatedAnnealingDecision
        /// \param _start_probability Probability to start choosing bad configurations
        /// \param _fall_rate
        /// \param _temperature_itereations Iterations with the same temperature
        ///
        OM_SimulatedAnnealingDecision(double _start_probability, double _fall_rate, double _temperature_itereations);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<DecisionPair> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        bool started;

        //! Temperature
        double T;
        double start_probability;
        double fall_rate;
        int temperature_iterations;

        //! Temp variables
        int relative_iteration_counter, current_probability, current_solution_cost, found_solution_cost;
        double relative_difference_cost;
};
