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
        GroupedParallelComputation(shared_ptr<Operator> _op);

        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

        //! From Codable
        string codeToSend();
};
