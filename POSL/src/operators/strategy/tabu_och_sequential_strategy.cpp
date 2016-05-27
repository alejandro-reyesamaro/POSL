#include "tabu_och_sequential_strategy.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <iostream>

using namespace std;

TabuOChSequentialStrategy::TabuOChSequentialStrategy(shared_ptr<OpenChannel> _OCH)
    : OCh(_OCH),
      output(nullptr)
{}

shared_ptr<ComputationData> TabuOChSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "sending data" << endl;
    output = OCh->execute(psp, input);
    if (output == nullptr) return nullptr;

    // Solution
    if(output->Tag() == TAGSOLUTION)
    {
        psp->SearchingWithOuterInformation_ON();
        shared_ptr<Solution> sol = static_pointer_cast<Solution>(output);
        psp->GetTabuObject()->addTabuSolution(sol->get_conf_by_ref());
    }
    // DecisionPair
    else if(output->Tag() == TAGDECISSIONPAIR)
    {
        psp->SearchingWithOuterInformation_ON();
        shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(output);
        psp->GetTabuObject()->addTabuSolution(pair->GetFound()->get_conf_by_ref());
    }
    // Neighborhoods
    //else if(result_och->Tag() == TAGNEIGHBORHOOD)

    return output;
}
