#include "om_one_permutation_neighborhood.h"

#include <iostream>

using namespace std;

OM_OnePermutationNeighborhood::OM_OnePermutationNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OnePermutationNeighborhood>(bench->Domains().size()))
{}

shared_ptr<Neighborhood> OM_OnePermutationNeighborhood::spcf_execute(shared_ptr<PSP>, shared_ptr<Solution> input)
{
    V->Init(input->GetConfiguration());
    return V;
}

string OM_OnePermutationNeighborhood::codeToSend()
{
    return OM_ONE_PERMUTATION_NEIGHBORHOOD_TOK;
}

string OM_OnePermutationNeighborhood::Tag()
{
    return "(N)One_Permutation";
}
