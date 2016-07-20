#pragma once

#include <vector>

class Packer
{
    public:
        Packer(int package_size);
        virtual std::vector<int> pack() = 0;

    protected:
        std::vector<int> package;
};
