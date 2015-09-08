#pragma once

#include "posl_iterator.h"
#include "../neighborhood.h"

#include <memory>

class ElementsChangeIterator : public POSL_Iterator<vector<int>>
{
    public:
        ElementsChangeIterator(shared_ptr<Neighborhood> _n);

        vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        shared_ptr<Neighborhood> neighborhood;
        int current;
};
