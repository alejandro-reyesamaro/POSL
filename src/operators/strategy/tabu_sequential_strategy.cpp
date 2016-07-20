#include "tabu_sequential_strategy.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <iostream>

using namespace std;

TabuSequentialStrategy::TabuSequentialStrategy(shared_ptr<CompoundModule> _M1)
    : M1(_M1),
      output(nullptr)
{}

shared_ptr<ComputationData> TabuSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "sending data" << endl;
    output = M1->execute(psp, input);

    // Solution
    if(output->Tag() == TAGSOLUTION)
    {
        shared_ptr<Solution> sol = static_pointer_cast<Solution>(output);
        psp->GetTabuObject()->addTabuSolution(sol->get_conf_by_ref());
    }
    // DecisionPair
    else if(output->Tag() == TAGDECISSIONPAIR)
    {
        shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(output);
        psp->GetTabuObject()->addTabuSolution(pair->GetFound()->get_conf_by_ref());
    }
    // Neighborhoods
    //else if(result_och->Tag() == TAGNEIGHBORHOOD)

    return input;
}
