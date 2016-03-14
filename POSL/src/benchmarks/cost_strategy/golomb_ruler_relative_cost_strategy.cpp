#include "golomb_ruler_relative_cost_strategy.h"

#include <iostream>
#include <algorithm>

using namespace std;

GolombRulerRelativeCostStrategy::GolombRulerRelativeCostStrategy()
{
}

void GolombRulerRelativeCostStrategy::initializeCostData(std::vector<int> &_configuration, int initial_cost)
{
    throw "Not yet implemented";
}

void GolombRulerRelativeCostStrategy::updateConfiguration(std::vector<int> &new_config)
{
    throw "Not yet implemented";
}

int GolombRulerRelativeCostStrategy::relativeSolutionCost(std::vector<int> &_configuration)
{
    throw "Not yet implemented";
}

int GolombRulerRelativeCostStrategy::relativeSolutionCost(std::vector<int> &new_config, T_Changes change)
{
    throw "Not yet implemented";
}

int GolombRulerRelativeCostStrategy::currentCost()
{
    throw "Not yet implemented";
}
