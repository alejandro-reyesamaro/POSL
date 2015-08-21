#include "decision_pair_packing_strategy.h"

#include <algorithm>

DecisionPairPackingStrategy::DecisionPairPackingStrategy(DecisionPair * _pair)
    : pair(_pair)
{}

vector<int> DecisionPairPackingStrategy::pack()
{
    int conf_size = pair->GetCurrent()->GetConfiguration().size();
    vector<int> package(conf_size * 2 + 2);
    // ID = 1
    package[0] = DECISIONPAIR_PACKING_ID;
    // Configuration size
    package[1] = conf_size;

    // Configuration 1 (current)
    vector<int> current_conf = pair->GetCurrent()->GetConfiguration();
    copy(current_conf.begin(), current_conf.end(), package.begin() + 2);

    // Configuration 1 (current)
    vector<int> found_conf = pair->GetFound()->GetConfiguration();
    copy(found_conf.begin(), found_conf.end(), package.begin() + 2 + conf_size);
    return package;
}

DecisionPair * DecisionPairPackingStrategy::unpack(int * pack, vector<Domain> domains)
{
    int conf_size = pack[1];
    vector<int> config1(conf_size);
    vector<int> config2(conf_size);
    copy(pack + 2, pack + conf_size + 2, config1.begin());
    copy(pack + conf_size + 2, pack + 2 * conf_size + 2, config2.begin());
    Solution * s1 = new Solution(domains, config1);
    Solution * s2 = new Solution(domains, config2);
    return new DecisionPair(s1, s2);
}

int DecisionPairPackingStrategy::BodySize()
{
    throw "Not implemented";
}

vector<int> DecisionPairPackingStrategy::body()
{
    throw "Not implemented";
}
