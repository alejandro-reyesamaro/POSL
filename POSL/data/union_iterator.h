#pragma once

#include "posl_iterator.h"
#include "union_neighborhood.h"

class UnionIterator : public POSL_Iterator<vector<int>>
{
    public:

        UnionIterator(UnionNeighborhood * _n);

        vector<int> GetNext();

        bool SomeNext();

        void Reset();

    private:
        UnionNeighborhood * neighborhood;
        int current;
};
