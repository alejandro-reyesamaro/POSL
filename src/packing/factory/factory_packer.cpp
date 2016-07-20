#include "factory_packer.h"

FactoryPacker::FactoryPacker(std::shared_ptr<Packer> _packer)
    : packer(_packer)
{}

std::vector<int> FactoryPacker::pack(){ return packer->pack(); }
