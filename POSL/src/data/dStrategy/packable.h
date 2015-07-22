#pragma once

#include <vector>

using namespace std;

class Packable
{
    public :
        virtual vector<int> pack() = 0;

        virtual int bodySize() = 0;
        virtual vector<int> body() = 0;
};
