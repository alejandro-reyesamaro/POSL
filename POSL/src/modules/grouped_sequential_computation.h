#pragma once

/**
 * POSL
 *
 * \file grouped_sequential_computation.h
 * \brief Class to group modules to be evaluated sequentially
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "grouped_computation.h"

/*!
 * \class GroupedSequentialComputation grouped_sequential_computation.h
 * \brief Class to group modules to be evaluated sequentially
 */
class GroupedSequentialComputation : public GroupedComputation
{
    public:
        //! Constructor
        /*!
        * \param _op The operator to be grouped
        */
        GroupedSequentialComputation(Operator * _op);

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input
        * \return The output of the module
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
