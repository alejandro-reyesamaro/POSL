#include "golomb_ruler_distances_cost_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>

#define PENALIZATION 10

using namespace std;

GolombRulerDistancesCostStrategy::GolombRulerDistancesCostStrategy(int _order, int _length)
    : order(_order),
      length(_length),
      measures(_length / 32 + 1, 0)
{}


int GolombRulerDistancesCostStrategy::solutionCost(std::vector<int> & configuration)
{
    measures.deactivateAll(); //measures.clearBits();// = new LongInt(table_length, 0);
    //vector<int> conf = sol->GetConfiguration();
    int cost = 0, penalty = 0;

    for(int i = 0; i < order - 1; i++)
        for(int j = i + 1; j < order; j++)
        {
            int distance = configuration[j] - configuration[i];
            if (distance <= 0)
                penalty ++;
            measures.activate(distance);
        }
    int not_measured = length - measures.bitCount();
    if(configuration[0] != 0)
        penalty += PENALIZATION * PENALIZATION;
    if(configuration[order - 1] != length)
        penalty += PENALIZATION * PENALIZATION;
    cost = not_measured + penalty * PENALIZATION;
    return cost;
}

