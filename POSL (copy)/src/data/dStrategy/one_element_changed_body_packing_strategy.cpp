#include "one_element_changed_body_packing_strategy.h"

OneElementChangedBodyPackingStrategy::OneElementChangedBodyPackingStrategy(vector<T_change> _changes)
    : changes(_changes),
      body(_changes.size() * 3)
{}

void OneElementChangedBodyPackingStrategy::update(vector<T_change> _changes)
{
    copy(_changes.begin(), _changes.end(), changes.begin());
}

int OneElementChangedBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    return changes.size() * 3;
}

vector<int> OneElementChangedBodyPackingStrategy::packBody()
{    
    int count = 0;
    for(vector<T_change>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        body[count++] = 1;
        body[count++] = (*it).pos;
        body[count++] = (*it).new_value;
    }
    return body;
}
