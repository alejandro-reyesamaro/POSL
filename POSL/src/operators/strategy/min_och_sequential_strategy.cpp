#include "min_och_sequential_strategy.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <iostream>
#include <typeinfo>

using namespace std;

MinOChSequentialStrategy::MinOChSequentialStrategy(shared_ptr<OpenChannel> _OCH, shared_ptr<CompoundModule> _M)
    : Och(_OCH), M(_M),
      result_och(nullptr),
      result_m(nullptr),
      mincrit(new MinCritComparison())
{}

shared_ptr<ComputationData> MinOChSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    result_och = Och->execute(psp, input);
    result_m = M->execute(psp, input);

    if (result_och == nullptr) return result_m;

    if(mincrit->isLessThan(result_m, result_och, psp))
    {
        //cout << "HERE " << result_m->Tag() << endl;
        return result_m;
    }
    else
    {
        psp->SearchingWithOuterInformation_ON();        
        // Solution
        if(result_och->Tag() == TAGSOLUTION)
        {
            shared_ptr<Solution> sol = static_pointer_cast<Solution>(result_och);
            psp->Start(sol->GetConfiguration());
            return result_och;
        }
        // DecisionPair
        else if(result_och->Tag() == TAGDECISSIONPAIR)
        {
            shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(result_och);
            psp->Start(pair->GetFound()->GetConfiguration());
            //psp->log("Taking outer solution...");
            return result_och;
        }
        // Neighborhoods
        else if(result_och->Tag() == TAGNEIGHBORHOOD)
            return result_och;

        throw "(POSL Exception) Not casting allowed (MinOChSequentialStrategy.evaluate)";
    }
}
