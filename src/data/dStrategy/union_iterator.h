#pragma once

#include "posl_iterator.h"
#include "../union_neighborhood.h"

#include <memory>

class UnionIterator : public POSL_Iterator//<std::vector<int>>
{
    public:

        UnionIterator(std::shared_ptr<UnionNeighborhood> _n);

        std::vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        std::shared_ptr<UnionNeighborhood> neighborhood;
        int current;
};
