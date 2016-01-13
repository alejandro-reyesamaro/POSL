#pragma once

#include "rearrange_strategy.h"
#include "../../tools/randomizer.h"

class AddAConstantRearrangeStrategy : public RearrangeStrategy
{
    public:
        AddAConstantRearrangeStrategy();

        std::shared_ptr<Solution> rearrangement(std::vector<int> current_configuration, std::shared_ptr<Benchmark> benchmark);

    private:
        Randomizer rand;
};
