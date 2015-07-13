#include "one_element_changed_body_packing_strategy.h"

OneElementChangedBodyPackingStrategy::OneElementChangedBodyPackingStrategy(vector<T_change> _changes)
    : changes(_changes)
{}

int OneElementChangedBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    return changes.size() * 3;
}

int * OneElementChangedBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];    
    int count = 0;
    for(vector<T_change>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 1;
        body[count++] = (*it).pos;
        body[count++] = (*it).new_value;
    }
    return body;
}
