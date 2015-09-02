#pragma once

#include "../packers/packer.h"

class FactoryPacker
{
    public:
        FactoryPacker(Packer * _packer);
        vector<int> pack();

    protected:
        Packer * packer;
};
