#include "om_one_permutation_neighborhood.h"

#include <iostream>

OM_OnePermutationNeighborhood::OM_OnePermutationNeighborhood(Benchmark * bench)
    : V(new OnePermutationNeighborhood(bench->Domains().size()))
{}

Neighborhood * OM_OnePermutationNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OnePermutationNeighborhood::codeToSend()
{
    return "B6";
}
