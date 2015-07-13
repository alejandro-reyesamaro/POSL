#include "multi_elements_changed_body_packing_strategy.h"

MultiElementsChangedBodyPackingStrategy::MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes)
    : changes(_changes)
{}

int MultiElementsChangedBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    // MAL !!!!!! : debe calcularse por cada cambio
    return changes.size() * changes[0].dim * 2;
}

int * MultiElementsChangedBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    int count = 0;
    int k = 0;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        int deg = changes[k].dim;
        body[count++] = deg;
        for(int i = 0; i < deg; i++)
        {
            body[count++] = (*it).positions[i];
            body[count++] = (*it).new_values[i];
        }
    }
    return body;
}
