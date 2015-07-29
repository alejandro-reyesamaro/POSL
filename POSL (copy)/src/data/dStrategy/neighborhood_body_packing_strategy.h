#pragma once

#include <vector>

using namespace std;

class NeighborhoodBodyPackingStrategy
{
    public:
        virtual int bodySize() = 0;
        virtual vector<int> packBody() = 0;
};
