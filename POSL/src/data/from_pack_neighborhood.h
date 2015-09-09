#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "t_changes.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

class FromPackNeighborhood : public Neighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        FromPackNeighborhood(int * pack);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size(){ return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();

    private:
        std::vector<T_Changes> changes;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
};
