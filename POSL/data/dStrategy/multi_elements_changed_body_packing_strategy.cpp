#include "multi_elements_changed_body_packing_strategy.h"

#include <iostream>

using namespace std;

MultiElementsChangedBodyPackingStrategy::MultiElementsChangedBodyPackingStrategy(vector<T_Nchanges> _changes)
    : changes(_changes)
{}

int MultiElementsChangedBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    // MAL !!!!!! : debe calcularse por cada cambio
    return changes.size() * (changes[0].dim * 2 + 1);
}

int * MultiElementsChangedBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    int count = 0;
    int k = 0;
    int c = 1;
    for(vector<T_Nchanges>::iterator it = changes.begin(); it != changes.end(); ++it)
    {
        int deg = changes[k].dim;
        body[count++] = deg;
        c++;
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
