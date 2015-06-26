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

/*!
 * \class DecisionPair decision_pair.h
 * \brief Class to represent a couple of solutions (current and new found)
 */
class DecisionPair : public ComputationData
{
    public:
        //! Constructor
        DecisionPair(Solution * _current, Solution * _found);

        //! Returns whether the solutions are equals or not
        /*!
        * \return True if the solutions are equals, false otherwise
        */
        bool equals();

        //! Returns the current solution
        Solution * GetCurrent();
        //! Returns the new found solution
        Solution * GetFound();

    private :
        //! Current solution
        Solution * current;
        //! New found solution
        Solution * found;
};
