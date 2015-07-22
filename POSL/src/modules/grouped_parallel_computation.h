#pragma once

/**
 * POSL
 *
 * \file grouped_parallel_computation.h
 * \brief Class to group modules to be evaluated in parallel
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "grouped_computation.h"

/*!
 * \class GroupedParallelComputation grouped_parallel_computation.h
 * \brief Class to group modules to be evaluated in parallel
 */
class GroupedParallelComputation : public GroupedComputation
{
    public:
        //! Constructor
        /*!
        * \param _op The operator to be grouped
        */
        GroupedParallelComputation(Operator * _op);

        //! Execute the O.M.
        /*!
        * \param psp The Problem Search Process
        * \param input Input
        * \return The output of the module
        */
        ComputationData * execute(PSP * psp, ComputationData * input);
};
