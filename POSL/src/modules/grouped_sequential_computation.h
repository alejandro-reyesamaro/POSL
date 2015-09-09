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
        GroupedSequentialComputation(std::shared_ptr<Operator> _op);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

        //! From Codable
        std::string codeToSend();
};
