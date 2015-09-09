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
        GroupedParallelComputation(std::shared_ptr<Operator> _op);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

        //! From Codable
        std::string codeToSend();
};
