#include "golomb_ruler_max_possible_distances_cost_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>

#define PENALIZATION 10

using namespace std;

GolombRulerMaxPossibleDistancesCostStrategy::GolombRulerMaxPossibleDistancesCostStrategy(int _order, int _length)
    //: cost_structure(make_shared<GolombRulerRelativeCostStructure>(_order,_length))
    : cost_structure(make_shared<GolombRulerCostStructure>(_order,_length))
{}


int GolombRulerMaxPossibleDistancesCostStrategy::solutionCost(std::vector<int> & configuration)
{
    cost_structure->init(configuration);
    return cost_structure->CurrentCost;
}
