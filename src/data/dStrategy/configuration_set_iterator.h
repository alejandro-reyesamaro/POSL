#pragma once

#include "posl_iterator.h"
#include "../configuration_set.h"

#include <memory>

class ConfigurationSetIterator : public POSL_Iterator
{
    public:
        ConfigurationSetIterator(std::shared_ptr<ConfigurationSet> _set);

        std::vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        std::shared_ptr<ConfigurationSet> set;
        int current;
};
