#pragma once

#include <vector>

using namespace std;

class Packer
{
    public:
        Packer(int package_size);
        virtual vector<int> pack() = 0;

    protected:
        vector<int> package;
};
