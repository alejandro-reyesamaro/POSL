#include "factory_packer.h"

FactoryPacker::FactoryPacker(shared_ptr<Packer> _packer)
    : packer(_packer)
{}

vector<int> FactoryPacker::pack(){ return packer->pack(); }
