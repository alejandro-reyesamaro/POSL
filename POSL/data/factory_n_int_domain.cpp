#include "factory_n_int_domain.h"

#include <iostream>

Factory_NIntDomain::Factory_NIntDomain(int min, int max)
{
    a = min;
    b = max;
}

vector<int> Factory_NIntDomain::BuildDomain()
{
    vector<int> vec;

    for (int i = a; i <= b; i++)
    {
        vec.push_back(i);
    }
    return vec;
}
