#pragma once

/**
 * POSL
 *
 * \file sickest_variable_strategy.h
 * \brief Interface to represent a strategy to return the variable with the highest projected cost
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

/*!
 * \class SickestVariableStrategy sickest_variable_strategy.h
 * \brief Interface to represent a strategy to compute the variable with the highest projected cost
 */
class SickestVariableStrategy
{
    public:
        //! Returns the variable with the highest projected cost
        /*!
            \return The index of the variable with the highest projected cost.
         */
        virtual int sickestVariable() = 0;
};
