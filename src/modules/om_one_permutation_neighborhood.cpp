#include "om_one_permutation_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_OnePermutationNeighborhood::OM_OnePermutationNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<OnePermutationNeighborhood>(bench->Dimension()))
{}

shared_ptr<Neighborhood> OM_OnePermutationNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
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
