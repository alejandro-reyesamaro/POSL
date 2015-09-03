#pragma once

#include <vector>

class DynamicNeighborhood
{
    public:
        virtual void Init(std::vector<int> _configuration) = 0;
};
