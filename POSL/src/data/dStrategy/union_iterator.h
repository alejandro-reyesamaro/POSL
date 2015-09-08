#pragma once

#include "posl_iterator.h"
#include "../union_neighborhood.h"

#include <memory>

class UnionIterator : public POSL_Iterator<vector<int>>
{
    public:

        UnionIterator(shared_ptr<UnionNeighborhood> _n);

        vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        shared_ptr<UnionNeighborhood> neighborhood;
        int current;
};
