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

#define DECISIONPAIR_PACKING_ID 658202

/*!
 * \class DecisionPair decision_pair.h
 * \brief Class to represent a couple of solutions (current and new found)
 */
class DecisionPair : public ComputationData
{
    public:
        DecisionPair(Solution * _current, Solution * _found);

        bool equals();
        FactoryPacker * BuildPacker();

        Solution * GetCurrent(){ return current; }
        Solution * GetFound(){ return found; }

        void update(vector<int> _current, vector<int> _found);
        void updateFromPack(int * pack);

    private :
        Solution * current;
        Solution * found;
};
