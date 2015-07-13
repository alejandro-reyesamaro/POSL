#include "decision_pair_packing_strategy.h"

#include <vector>

DecisionPairPackingStrategy::DecisionPairPackingStrategy(DecisionPair * _pair)
    : pair(_pair)
{}

int * DecisionPairPackingStrategy::pack()
{
    int conf_size = pair->GetCurrent()->configuration.size();
    int * package = new int[conf_size * 2 + 2];
    // ID = 1
    package[0] = 1;
    // Configuration size
    package[1] = conf_size;

    int count = 2;

    // Configuration 1 (current)
    vector<int> current_conf = pair->GetCurrent()->configuration;
    for(vector<int>::iterator it = current_conf.begin(); it != current_conf.end(); ++it)
        package[count++] = *it;

    // Configuration 1 (current)
    vector<int> found_conf = pair->GetFound()->configuration;
    for(vector<int>::iterator it = found_conf.begin(); it != found_conf.end(); ++it)
        package[count++] = *it;

    return package;
}

int DecisionPairPackingStrategy::BodySize()
{
    throw "Not implemented";
}

int * DecisionPairPackingStrategy::body()
{
    throw "Not implemented";
}
