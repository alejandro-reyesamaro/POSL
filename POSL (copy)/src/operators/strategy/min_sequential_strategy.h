/**
 * POSL
 *
 * \file min_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator MIN
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "sequential_execution_strategy.h"

/*!
 * \class MinSequentialStrategy min_sequential_strategy.h
 * \brief Strategy of sequential computation for the operator MIN
 */
class MinSequentialStrategy : public SequentialExecutionStrategy
{
    public:
        //! Constructor
        MinSequentialStrategy(CompoundModule * _M1, CompoundModule * _M2);

        //! (override) The result of evaluating a Compound Module (Sequentially)
        /*!
        * \param bench A Benchmark
        * \param input The input of the Compound Module
        * \return <ps> Returns Execute( M1 ) or Execute( M2 ) </pc> (some minimum criteria)
        */
        ComputationData * evaluate(PSP * psp, ComputationData * input);

    private:
        //! Left Compund Module
        CompoundModule * M1;
        //! Right Compund Module
        CompoundModule * M2;
};
