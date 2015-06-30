#pragma once

#include "posl_iterator.h"
#include "neighborhood.h"

class ElementsChangeIterator : public POSL_Iterator<vector<int>>
{
    public:

        ElementsChangeIterator(Neighborhood * _n);

        vector<int> GetNext();

        bool SomeNext();

        void Reset();

    private:
        //shared_ptr<OneElementChangedNeighborhood> neighborhood;
        Neighborhood * neighborhood;
        int current;
};
