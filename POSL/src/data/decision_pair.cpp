#include "decision_pair.h"
#include "../packing/factory/factory_decision_pair_packer.h"

#include <iostream>

DecisionPair::DecisionPair(std::shared_ptr<Solution> _current, std::shared_ptr<Solution> _found)
    : current(_current), found(_found)
{}

void DecisionPair::update(std::vector<int> _current, std::vector<int> _found)
{
    current->UpdateConfiguration(_current);
    found->UpdateConfiguration(_found);
}

void DecisionPair::updateFromPack(int * pack)
{
    int conf_size = pack[1];
    std::vector<int> config1(conf_size);
    std::vector<int> config2(conf_size);
    std::copy(pack + 2, pack + conf_size + 2, config1.begin());
    std::copy(pack + conf_size + 2, pack + 2 * conf_size + 2, config2.begin());
    current->UpdateConfiguration(config1);
    found->UpdateConfiguration(config2);
}

bool DecisionPair::equals(){ return current->equal(found); }

std::shared_ptr<FactoryPacker> DecisionPair::BuildPacker(){ return std::make_shared<FactoryDecisionPairPacker>(shared_from_this()); }
