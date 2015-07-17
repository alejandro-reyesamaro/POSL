#include "multi_elements_changed_body_packing_strategy.h"

#include <iostream>

MultiElementsChangedBodyPackingStrategy::MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes)
    : changes(_changes)
{}

int MultiElementsChangedBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    int degs = 0;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
        degs = degs + (*it).dim * 2;
    return degs + changes.size();
}

vector<int> MultiElementsChangedBodyPackingStrategy::packBody()
{
    vector<int> body(bodySize());
    int count = 0;
    int k = 0;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        int deg = changes[k].dim;
        body[count++] = deg;
        for(int i = 0; i < deg; i++)
        {
            int pos = (*it).positions[i];
            int value = (*it).new_values[i];
            body[count++] = pos;
            body[count++] = value;
        }
    }
    return body;
}
