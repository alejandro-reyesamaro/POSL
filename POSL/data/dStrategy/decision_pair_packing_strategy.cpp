#include "decision_pair_packing_strategy.h"

#include <algorithm>

DecisionPairPackingStrategy::DecisionPairPackingStrategy(DecisionPair * _pair)
    : pair(_pair)
{}

vector<int> DecisionPairPackingStrategy::pack()
{
    int conf_size = pair->GetCurrent()->configuration.size();   
    vector<int> package(conf_size * 2 + 2);
    // ID = 1
    package[0] = 1;
    // Configuration size
    package[1] = conf_size;

    // Configuration 1 (current)
    vector<int> current_conf = pair->GetCurrent()->configuration;
    copy(current_conf.begin(), current_conf.end(), package.begin() + 2);

    // Configuration 1 (current)
    vector<int> found_conf = pair->GetFound()->configuration;
    copy(found_conf.begin(), found_conf.end(), package.begin() + 2 + conf_size);
    return package;
}

int DecisionPairPackingStrategy::BodySize()
{
    throw "Not implemented";
}

vector<int> DecisionPairPackingStrategy::body()
{
    throw "Not implemented";
}
