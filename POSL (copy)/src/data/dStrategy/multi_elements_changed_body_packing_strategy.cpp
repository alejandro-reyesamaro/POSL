#include "multi_elements_changed_body_packing_strategy.h"

#include <iostream>

int bSize(vector<T_Nchanges> _changes);

MultiElementsChangedBodyPackingStrategy::MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes)
    : changes(_changes),
      body_package(bSize( _changes))
{}

void MultiElementsChangedBodyPackingStrategy::update(vector<T_Nchanges> _changes)
{
    copy(_changes.begin(), _changes.end(), changes.begin());
}

int bSize(vector<T_Nchanges> _changes)
{
    // Each change * (deg, pos and value)
    int degs = 0;
    for(vector<T_Nchanges>::iterator it = _changes.begin(); it != _changes.end(); ++it)
        degs = degs + (*it).dim * 2;
    return degs + _changes.size();
}

int MultiElementsChangedBodyPackingStrategy::bodySize(){ return bSize(changes); }

vector<int> MultiElementsChangedBodyPackingStrategy::packBody()
{
    int count = 0;
    int k = 0;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        int deg = changes[k].dim;
        body_package[count++] = deg;
        for(int i = 0; i < deg; i++)
        {
            int pos = (*it).positions[i];
            int value = (*it).new_values[i];
            body_package[count++] = pos;
            body_package[count++] = value;
        }
    }
    return body_package;
}
