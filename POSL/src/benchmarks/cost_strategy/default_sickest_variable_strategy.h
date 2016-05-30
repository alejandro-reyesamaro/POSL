#pragma once

/**
 * POSL
 *
 * \file default_sickest_variable_strategy.h
 * \brief Class to represent a default strategy to return the variable with the highest projected cost
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "sickest_variable_strategy.h"
#include "projectable_cost.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/random_generator.h"

#include <memory>

/*!
 * \class DefaultSickestVariableStrategy default_sickest_variable_strategy.h
 * \brief Class to represent a default strategy to compute the variable with the highest projected cost
 */
class DefaultSickestVariableStrategy : public SickestVariableStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _size Size of a problem configuration.
            \param iProjectable_cost An instance of a class able to projects the cost of a variable.
         */
        DefaultSickestVariableStrategy(int _size, std::shared_ptr<ProjectableCost> iProjectable_cost);

        //! From <SickestVariableStrategy>
        int sickestVariable();

    private:
        int Size;
        //! A ProjectableCost instance
        std::shared_ptr<ProjectableCost> projectable_cost_component;
        //! A temporal vector to store the dab variables (same projected cost)
        FixedSizeVector<int> bad_variables;
        //! Random generator to choose the <i>bad variable</i>s
        RandomGenerator r_gen;
};
