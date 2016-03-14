#pragma once

#include "rearrange_strategy.h"
#include "../../tools/randomizer.h"

class AddAConstantRearrangeStrategy : public RearrangeStrategy
{
    public:
        AddAConstantRearrangeStrategy();

        std::shared_ptr<Solution> rearrangement(std::shared_ptr<PSP> psp, std::vector<int> current_configuration);

    //private:

};
