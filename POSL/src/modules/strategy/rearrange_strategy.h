#pragma once

#include "../../data/solution.h"
#include "../../solver/psp.h"

class RearrangeStrategy
{
    public:
        virtual std::shared_ptr<Solution> rearrangement(std::shared_ptr<PSP> psp,  std::vector<int> current_configuration) = 0;
};
