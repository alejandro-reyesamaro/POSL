#include "decision_pair_packing_strategy.h"

#include <algorithm>
#include <iostream>
using namespace std;

DecisionPairPackingStrategy::DecisionPairPackingStrategy(DecisionPair * _pair)
    : current_conf (_pair->GetCurrent()->GetConfiguration()),
      found_conf (_pair->GetFound()->GetConfiguration()),
      package(_pair->GetCurrent()->GetConfiguration().size() * 2 + 2)
{}

void DecisionPairPackingStrategy::update(vector<int> current, vector<int> found)
{
    copy(current.begin(), current.end(), current_conf.begin());
    copy(found.begin(), found.end(), found_conf.begin());
}

vector<int> DecisionPairPackingStrategy::pack()
{
    // ID = 1
    package[0] = DECISIONPAIR_PACKING_ID;
    // Configuration size
    package[1] = current_conf.size();

    // Configuration 1 (current)
    //vector<int> current_conf = pair->GetCurrent()->GetConfiguration();
    copy(current_conf.begin(), current_conf.end(), package.begin() + 2);

    // Configuration 1 (current)
    //vector<int> found_conf = pair->GetFound()->GetConfiguration();
    copy(found_conf.begin(), found_conf.end(), package.begin() + 2 + current_conf.size());
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
    throw "(POSL Exception) Not implemented (DecisionPair.BodySize)";
}

vector<int> DecisionPairPackingStrategy::body()
{
    throw "(POSL Exception) Not implemented (DecisionPair.body)";
}
