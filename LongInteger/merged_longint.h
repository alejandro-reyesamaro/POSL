#pragma once

#include "long_int.h"

#include <vector>

class MergedLongInt
{
    public:
        MergedLongInt(LongInt & a, LongInt & b);
        LongInt long_or();
        LongInt long_and();
        bool equal();

        vector<int>::iterator it_upper;
        vector<int>::iterator it_lower;
        int _max, _min;
};
