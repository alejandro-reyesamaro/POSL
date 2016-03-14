#include "add_a_constant_rearrange_strategy.h"

#include <algorithm>
#include <iostream>

using namespace std;

AddAConstantRearrangeStrategy::AddAConstantRearrangeStrategy()
{}

shared_ptr<Solution> AddAConstantRearrangeStrategy::rearrangement(std::shared_ptr<PSP> psp, std::vector<int> current_configuration)
{
    int N = * max_element(current_configuration.begin(), current_configuration.end()) + 1;
    int size = current_configuration.size();
    int C = psp->GetRandomizer()->NextInt(1, N-2);
    for(int i = 0; i < size; i++)
        current_configuration[i] = (current_configuration[i] + C) % N;
    return make_shared<Solution>(psp->GetBenchmark()->Domains(), current_configuration);
}
