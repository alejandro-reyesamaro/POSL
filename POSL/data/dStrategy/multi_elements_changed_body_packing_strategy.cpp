#include "multi_elements_changed_body_packing_strategy.h"

MultiElementsChangedBodyPackingStrategy::MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes)
    : changes(_changes)
{}

int MultiElementsChangedBodyPackingStrategy::bodySize()
{
    // Each change (pos and value) * number of changes + deg
    return changes.size() * degree() * 2 + 1;
}

int MultiElementsChangedBodyPackingStrategy::degree()
{
    return changes[0].dim;
}

int * MultiElementsChangedBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    // Deg
    body[0] = degree();
    // ...
    int count = 1;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        for(int i = 0; i < degree(); i++)
        {
            body[count++] = (*it).positions[i];
            body[count++] = (*it).new_values[i];
        }
    }
    return body;
}
