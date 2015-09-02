#include "factory_decision_pair_packer.h"

FactoryDecisionPairPacker::FactoryDecisionPairPacker(DecisionPair * pair)
    : FactoryPacker(new DecisionPairPacker(pair))
{}
