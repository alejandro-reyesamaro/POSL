#pragma once

#include "../packers/packer.h"

#include <memory>

class FactoryPacker
{
    public:
        FactoryPacker(std::shared_ptr<Packer> _packer);
        std::vector<int> pack();

    protected:
        std::shared_ptr<Packer> packer;
};
