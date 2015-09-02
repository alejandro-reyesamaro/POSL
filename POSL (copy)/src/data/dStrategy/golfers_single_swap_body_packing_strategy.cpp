#include "golfers_single_swap_body_packing_strategy.h"
#include <algorithm>

GolfersSingleSwapBodyPackingStrategy::GolfersSingleSwapBodyPackingStrategy(vector<T_SwapChanges> _changes, vector<int> _configuration)
    : changes(_changes),
      configuration(_configuration),
      body(_changes.size() * 5)
{}

void GolfersSingleSwapBodyPackingStrategy::update(vector<T_SwapChanges> _changes, vector<int> _configuration)
{
    copy(_changes.begin(), _changes.end(), changes.begin());
    copy(_configuration.begin(), _configuration.end(), configuration.begin());
}

int GolfersSingleSwapBodyPackingStrategy::bodySize()
{
    // Each change (deg, pos and value 2 times)
    return changes.size() * 5;
}

vector<int> GolfersSingleSwapBodyPackingStrategy::packBody()
{
    int count = 0;
    for(vector<T_SwapChanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 2;
        body[count++] = (*it).pos1;
        body[count++] = configuration[(*it).pos2];
        body[count++] = (*it).pos2;
        body[count++] = configuration[(*it).pos1];
    }
    return body;
}
