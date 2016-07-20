#pragma once

#include "posl_iterator.h"
#include "../neighborhood.h"

#include <memory>

class ElementsChangeIterator : public POSL_Iterator//<std::vector<int>>
{
    public:
        ElementsChangeIterator(std::shared_ptr<Neighborhood> _n);

        std::vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        std::shared_ptr<Neighborhood> neighborhood;
        int current;
};
