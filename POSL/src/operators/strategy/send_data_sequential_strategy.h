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

/*!
 * \class SendDataSequentialStrategy send_data_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator Send Data
 */
class SendDataSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        SendDataSequentialStrategy(shared_ptr<CompoundModule> _M1);

        shared_ptr<ComputationData> evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);

    private:
        shared_ptr<CompoundModule> M1;
        shared_ptr<ComputationData> output;
};
