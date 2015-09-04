#include "decision_pair.h"
#include "../packing/factory/factory_decision_pair_packer.h"

#include <iostream>
using namespace std;

DecisionPair::DecisionPair(Solution *_current, Solution *_found)
    : current(_current), found(_found)
{}

void DecisionPair::update(vector<int> _current, vector<int> _found)
{
    current->UpdateConfiguration(_current);
    found->UpdateConfiguration(_found);
}

void DecisionPair::updateFromPack(int * pack)
{
    int conf_size = pack[1];
    vector<int> config1(conf_size);
    vector<int> config2(conf_size);
    copy(pack + 2, pack + conf_size + 2, config1.begin());
    copy(pack + conf_size + 2, pack + 2 * conf_size + 2, config2.begin());
    current->UpdateConfiguration(config1);
    found->UpdateConfiguration(config2);
}

bool DecisionPair::equals(){ return current->equal(found); }

FactoryPacker * DecisionPair::BuildPacker(){ return new FactoryDecisionPairPacker(this); }
