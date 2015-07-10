#include "golfers_single_swap_body_packing_strategy.h"

GolfersSingleSwapBodyPackingStrategy::GolfersSingleSwapBodyPackingStrategy(vector<T_SwapChanges> _changes, vector<int> _configuration)
    : changes(_changes), configuration(_configuration)
{}

int GolfersSingleSwapBodyPackingStrategy::bodySize()
{
    // Each change (pos and value) * number of changes + deg
    return changes.size() * degree() * 2 + 1;
}

int GolfersSingleSwapBodyPackingStrategy::degree()
{
    return 2;
}

int * GolfersSingleSwapBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    // Deg
    body[0] = degree();
    // ...
    int count = 1;
    for(vector<T_SwapChanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = (*it).pos1;
        body[count++] = configuration[(*it).pos2];
        body[count++] = (*it).pos2;
        body[count++] = configuration[(*it).pos1];
    }
    return body;
}
