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

bool DecisionPair::equals(){ return current->equal(found); }

FactoryPacker * DecisionPair::BuildPacker(){ return new FactoryDecisionPairPacker(this); }
