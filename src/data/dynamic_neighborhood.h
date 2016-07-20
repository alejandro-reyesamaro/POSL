#pragma once

#include "../solver/psp.h"

#include <vector>
#include <memory>

class DynamicNeighborhood
{
    public:
        virtual void Init(std::shared_ptr<PSP> psp, std::vector<int> & _configuration) = 0;
};
