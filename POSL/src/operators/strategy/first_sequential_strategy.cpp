#include "first_sequential_strategy.h"
#include "../../data/decision_pair.h"
#include "../../data/neighborhood.h"

#include <iostream>
#include <typeinfo>

using namespace std;

FirstSequentialStrategy::FirstSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2),
      result_m1(nullptr),
      result_m2(nullptr)
{}

shared_ptr<ComputationData> FirstSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    //cout << "first" << endl;
    result_m1 = M1->execute(psp, input);
    result_m2 = M2->execute(psp, input);

    return (result_m1 != nullptr) ? result_m1 : result_m2;
}
