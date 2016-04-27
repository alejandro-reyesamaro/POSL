#pragma once

#include "sickest_variable_strategy.h"
#include "projectable_cost.h"
#include "../../tools/fixed_size_vector.h"
#include "../../tools/random_generator.h"

#include <memory>

class DefaultSickestVariableStrategy : public SickestVariableStrategy
{
    public:
        DefaultSickestVariableStrategy(int _size, std::shared_ptr<ProjectableCost> iProjectable_cost);
        int sickestVariable();

    private:
        int Size;
        std::shared_ptr<ProjectableCost> projectable_cost_component;
        FixedSizeVector<int> bad_variables;
        RandomGenerator r_gen;
};
