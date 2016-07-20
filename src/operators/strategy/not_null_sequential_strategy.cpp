#include "not_null_sequential_strategy.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <iostream>
#include <typeinfo>

using namespace std;

NotNullSequentialStrategy::NotNullSequentialStrategy(shared_ptr<OpenChannel> _OCH, shared_ptr<CompoundModule> _M)
    : Och(_OCH), M(_M),
      result_och(nullptr),
      result_m(nullptr)
{}

shared_ptr<ComputationData> NotNullSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "notnull" << endl;
    result_och = Och->execute(psp, input);    

    if (result_och == nullptr)
    {
        result_m = M->execute(psp, input);
        return result_m;
    }
    else
    {
        psp->SearchingWithOuterInformation_ON();
        // Solution
        if(result_och->Tag() == TAGSOLUTION)
        {
            shared_ptr<Solution> sol = static_pointer_cast<Solution>(result_och);
            psp->Start(sol->get_conf_by_ref());
            return result_och;
        }
        // DecisionPair
        else if(result_och->Tag() == TAGDECISSIONPAIR)
        {
            shared_ptr<DecisionPair> pair = static_pointer_cast<DecisionPair>(result_och);
            psp->Start(pair->GetFound()->get_conf_by_ref());
            //psp->log("Taking outer solution...");
            return result_och;
        }
        // Neighborhoods
        else if(result_och->Tag() == TAGNEIGHBORHOOD)
            return result_och;

        throw "(POSL Exception) Not casting allowed (NotNullSequentialStrategy.evaluate)";
    }
}
