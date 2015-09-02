#pragma once

#include <vector>
#include "../data/computation_data.h"

using namespace std;

class Packer
{
    public:
        virtual vector<int> pack() = 0;
};
