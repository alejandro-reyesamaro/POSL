#include "one_element_changed_body_packing_strategy.h"

OneElementChangedBodyPackingStrategy::OneElementChangedBodyPackingStrategy(vector<T_change> _changes)
    : changes(_changes)
{}

int OneElementChangedBodyPackingStrategy::bodySize()
{
    // Each change (pos and value) + deg
    return changes.size() * 2 + 1;
}

int OneElementChangedBodyPackingStrategy::degree()
{
    return 1;
}

int * OneElementChangedBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    // Deg
    body[0] = degree();
    // ...
    int count = 1;
    for(vector<T_change>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = (*it).pos;
        body[count++] = (*it).new_value;
    }
    return body;
}
