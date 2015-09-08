#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dStrategy/elements_change_iterator.h"
#include "t_changes.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

class FromPackNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:
        FromPackNeighborhood(int * pack);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator(){ return make_shared<ElementsChangeIterator>(this); }
        int size(){ return changes.size(); }
        vector<T_Changes> GetChanges() { return changes; }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();

    private:
        vector<T_Changes> changes;
        shared_ptr<ApplyChangeBehavior> changeAtBhv;
};
