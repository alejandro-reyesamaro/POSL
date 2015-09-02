#include "decision_pair.h"
#include "../packing/factory/factory_decision_pair_packer.h"

#include <iostream>
using namespace std;

DecisionPair::DecisionPair(Solution *_current, Solution *_found)
    : current(_current), found(_found)
{}

void DecisionPair::update(Solution * _current, Solution * _found)
{
    current = _current;
    found = _found;
}

bool DecisionPair::equals(){ return current->equal(found); }

Solution * DecisionPair::GetCurrent(){ return current; }

Solution * DecisionPair::GetFound(){ return found; }

FactoryPacker * DecisionPair::BuildPacker(){ return new FactoryDecisionPairPacker(this); }
