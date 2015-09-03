#pragma once

#include <vector>

class DynamicNeighborhood
{
    public:
        virtual void update(std::vector<int> _configuration) = 0;
};
