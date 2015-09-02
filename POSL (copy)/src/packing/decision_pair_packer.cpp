#include "decision_pair_packer.h"

#include <algorithm>

DecisionPairPacker::DecisionPairPacker(DecisionPair * pair)
    : current_configuration(pair->GetCurrent()->GetConfiguration()),
      found_configuration(pair->GetFound()->GetConfiguration())
{}

void DecisionPairPacker::update(vector<int> current, vector<int> found)
{
    copy(current.begin(), current.end(), current_configuration.begin());
    copy(found.begin(), found.end(), found_configuration.begin());
}

vector<int> DecisionPairPacker::pack()
{
    // ID = 1
    package[0] = DECISIONPAIR_PACKING_ID;
    // Configuration size
    package[1] = current_configuration.size();

    // Configuration 1 (current)
    //vector<int> current_conf = pair->GetCurrent()->GetConfiguration();
    copy(current_configuration.begin(), current_configuration.end(), package.begin() + 2);

    // Configuration 1 (current)
    //vector<int> found_conf = pair->GetFound()->GetConfiguration();
    copy(found_configuration.begin(), found_configuration.end(), package.begin() + 2 + current_configuration.size());
    return package;
}
