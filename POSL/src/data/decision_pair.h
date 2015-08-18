#pragma once

/**
 * POSL
 *
 * \file decision_pair.h
 * \brief Class to represent a couple of solutions (current and new found)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "computation_data.h"
#include "solution.h"
#include "dStrategy/packable.h"
#include "dStrategy/packing_strategy.h"

#define DECISIONPAIR_PACKING_ID 658203

/*!
 * \class DecisionPair decision_pair.h
 * \brief Class to represent a couple of solutions (current and new found)
 */
class DecisionPair : public ComputationData, public Packable
{
    public:
        //! Constructor
        DecisionPair(Solution * _current, Solution * _found);

        //! Returns whether the solutions are equals or not
        /*!
        * \return True if the solutions are equals, false otherwise
        */
        bool equals();

        //! From Packable
        vector<int> pack();
        int bodySize();
        vector<int> body();

        //! Returns the current solution
        Solution * GetCurrent();
        //! Returns the new found solution
        Solution * GetFound();

    private :
        //! Current solution
        Solution * current;
        //! New found solution
        Solution * found;
        //! Packing strategy
        PackingStrategy * packing_strategy;

};
