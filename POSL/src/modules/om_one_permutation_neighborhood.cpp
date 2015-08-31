#include "om_one_permutation_neighborhood.h"
#include "../data/one_permutation_neighborhood.h"

#include <iostream>

OM_OnePermutationNeighborhood::OM_OnePermutationNeighborhood(){}

Neighborhood * OM_OnePermutationNeighborhood::spcf_execute(PSP * psp, Solution * input)
{
    Neighborhood * V = new OnePermutationNeighborhood(input);
    return V;
}

string OM_OnePermutationNeighborhood::codeToSend()
{
    return "B6";
}
