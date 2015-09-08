#include "factory_decision_pair_packer.h"

FactoryDecisionPairPacker::FactoryDecisionPairPacker(shared_ptr<DecisionPair> pair)
    : FactoryPacker(make_shared<DecisionPairPacker>(pair))
{}
