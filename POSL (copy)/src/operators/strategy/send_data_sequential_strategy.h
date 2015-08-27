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
        //! Constructor
        SendDataSequentialStrategy(CompoundModule * _M1);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) and send the result </pc>
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! The Module
        CompoundModule * M1;
};
