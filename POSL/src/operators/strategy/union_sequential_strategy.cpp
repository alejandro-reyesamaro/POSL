#include "union_sequential_strategy.h"

#include <iostream>

UnionSequentialStrategy::UnionSequentialStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2),
      v1(nullptr),
      v2(nullptr)
{}

shared_ptr<ComputationData> UnionSequentialStrategy::evaluate(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    v1 = static_pointer_cast<Neighborhood>(M1->execute(psp, input));
    v2 = static_pointer_cast<Neighborhood>(M2->execute(psp, input));

    if (v1 == nullptr) return v2;
    if (v2 == nullptr) return v1;

    return make_shared<UnionNeighborhood>(static_pointer_cast<Solution>(input), v1, v2);
}
