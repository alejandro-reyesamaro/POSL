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

#include <functional>

#define DECISIONPAIR_PACKING_ID 658202
#define TAGDECISSIONPAIR "cd_DP"

/*!
 * \class DecisionPair decision_pair.h
 * \brief Class to represent a couple of solutions (current and new found)
 */
class DecisionPair : public ComputationData, public std::enable_shared_from_this<DecisionPair>
{
    public:
        DecisionPair(std::shared_ptr<Solution> _current, std::shared_ptr<Solution> _found);

        bool equals();
        std::shared_ptr<FactoryPacker> BuildPacker();

        std::shared_ptr<Solution> GetCurrent(){ return current; }
        std::shared_ptr<Solution> GetFound(){ return found; }

        void update(std::vector<int> &_current, std::vector<int> _found);
        void updateFromPack(int * pack);

        std::string Tag() { return TAGDECISSIONPAIR; }

        int comapareTo(std::shared_ptr<ComputationData> other,
                       std::function<int(std::shared_ptr<ComputationData>)> criteria);

    private :
        std::shared_ptr<Solution> current;
        std::shared_ptr<Solution> found;
};
