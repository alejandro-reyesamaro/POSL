#pragma once

/**
 * POSL
 *
 * \file projectable_cost.h
 * \brief Interface to represent the a class that can projec the cost of a variable
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

/*!
 * \class ProjectableCost projectable_cost.h
 * \brief Interface to represent the a class that can projec the cost of a variable
 */
class ProjectableCost
{
    public:
        //! Computes the projected cost of a variable.
        /*!
            \param variable_index Index of a variable.
            \return Projected cost of a given variable.
         */
        virtual int costOnVariable(int variable_index) = 0;
};
