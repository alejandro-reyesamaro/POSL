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
    result_och = Och->execute(psp, input);
    result_m = M->execute(psp, input);

    return (result_och == nullptr) ? result_m : result_och;
}
