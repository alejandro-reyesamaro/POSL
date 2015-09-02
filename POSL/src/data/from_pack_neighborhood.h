#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dStrategy/elements_change_iterator.h"
#include "t_nchanges.h"

#include <random>

class FromPackNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:

        FromPackNeighborhood(int * pack);

        POSL_Iterator<vector<int>> * getIterator(){ return new ElementsChangeIterator(this); }
        int size(){ return changes.size(); }
        vector<T_Nchanges> GetChanges() { return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();

    private:
        vector<int> applyChangeAt(int index);

        vector<T_Nchanges> changes;
};
