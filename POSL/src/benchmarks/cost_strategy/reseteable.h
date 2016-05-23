#pragma once

#include <vector>

class Reseteable
{
    public:
        virtual std::vector<int> Reset() = 0;
};
