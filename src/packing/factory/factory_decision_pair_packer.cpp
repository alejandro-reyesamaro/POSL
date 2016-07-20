#include "factory_decision_pair_packer.h"

FactoryDecisionPairPacker::FactoryDecisionPairPacker(std::shared_ptr<DecisionPair> pair)
    : FactoryPacker(std::make_shared<DecisionPairPacker>(pair))
{}
