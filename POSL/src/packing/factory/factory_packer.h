#pragma once

#include "../packers/packer.h"

class FactoryPacker
{
    public:
        FactoryPacker(shared_ptr<Packer> _packer);
        vector<int> pack();

    protected:
        shared_ptr<Packer> packer;
};
