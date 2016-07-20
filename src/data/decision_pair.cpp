#include "decision_pair.h"
#include "../packing/factory/factory_decision_pair_packer.h"

#include <iostream>

using namespace std;

DecisionPair::DecisionPair(shared_ptr<Solution> _current, shared_ptr<Solution> _found)
    : current(_current),
      found(_found)
{}

void DecisionPair::update(std::vector<int> & _current, std::vector<int> _found)
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

std::shared_ptr<FactoryPacker> DecisionPair::BuildPacker(){ return std::make_shared<FactoryDecisionPairPacker>(shared_from_this()); }

int DecisionPair::comapareTo(std::shared_ptr<ComputationData> other,
                             std::function<int(std::shared_ptr<ComputationData>)> criteria)
{
    if(other->Tag() == TAGDECISSIONPAIR)
    {
        int ranking_this = criteria(found);
        int ranking_other = criteria(static_pointer_cast<DecisionPair>(other)->GetFound());
        int difference = ranking_this - ranking_other;
        return (difference == 0) ? 0 : difference / abs(difference);
    }
    else throw "(POSL Exception) Not compearing allowed (DecisionPair::comapareTo)";
}
