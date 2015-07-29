#pragma once

#include <vector>

using namespace std;

class PackingStrategy
{
    public:
        virtual vector<int> pack() = 0;
        virtual int BodySize() = 0;
        virtual vector<int> body() = 0;
};
