#include "merged_longint.h"

#include <iostream>
using namespace std;

MergedLongInt::MergedLongInt(LongInt &a, LongInt &b)
{
    _max = max(a.length(), b.length());
    _min = min(a.length(), b.length());

    it_upper = (a.length() > b.length()) ? a.value.begin() : b.value.begin();
    it_lower = (a.length() > b.length()) ? b.value.begin() : a.value.begin();
}

LongInt MergedLongInt::long_or()
{
    vector<int> aux (_max);
    vector<int>::iterator it_u = it_upper;
    vector<int>::iterator it_l = it_lower;
    int i;
    for(i = 0; i < _min; i++)
    {
        aux[i] = *it_l | *it_u;
        it_l ++;
        it_u ++;
    }
    for(int j = i; j < _max; j++)
    {
        aux[j] = *it_u;
        it_u ++;
    }
    return LongInt(_max, aux);
}

LongInt MergedLongInt::long_and()
{
    vector<int> aux (_max, 0);
    vector<int>::iterator it_u = it_upper;
    vector<int>::iterator it_l = it_lower;
    for(int i = 0; i < _min; i++)
    {
        aux[i] = *it_l & *it_u;
        it_l ++;
        it_u ++;
    }
    return LongInt(_max, aux);
}

bool MergedLongInt::equal()
{
    if (_max != _min) return false;
    bool eq = true;
    vector<int>::iterator it_u = it_upper;
    vector<int>::iterator it_l = it_lower;
    for(int i = 0; i < _min; i++)
    {
        eq = eq && *it_l == *it_u;
        it_u ++;
        it_l ++;
    }
    return eq;
}
