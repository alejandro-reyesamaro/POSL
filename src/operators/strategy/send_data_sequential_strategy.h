#pragma once
/**
 * POSL
 *
 * \file send_data_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Send Data
 * \author Alejandro Reyes
 * \date 2015-08-19
 */

#include "sequential_execution_strategy.h"
#include "../../expressions/iteretion_bound_expression.h"
#include "../../tools/chronometer.h"

/*!
 * \class SendDataSequentialStrategy send_data_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Send Data
 */
class SendDataSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        SendDataSequentialStrategy(std::shared_ptr<CompoundModule> _M1);

        std::shared_ptr<ComputationData> evaluate(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);
        void addDestiny(int pID);

    private:
        std::shared_ptr<Chronometer> chrono;
        std::shared_ptr<CompoundModule> M1;
        std::shared_ptr<ComputationData> output;
        std::shared_ptr<Comunicator> comm;
        std::vector<int> destinies;
        std::vector<int> vector_pack;

        bool log_first_delivery;

};
