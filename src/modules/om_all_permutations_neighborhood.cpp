#include "om_all_permutations_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_AllPermutationsNeighborhood::OM_AllPermutationsNeighborhood(shared_ptr<Benchmark> bench, int part)
    : V(make_shared<AllPermutationsNeighborhood>(bench->Dimension(), part))
{}

shared_ptr<Neighborhood> OM_AllPermutationsNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    return V;
}

string OM_AllPermutationsNeighborhood::codeToSend()
{
    return OM_ALL_PERMUTATIONS_NEIGHBORHOOD_TOK;// "OM_V.AllPerms";
}

string OM_AllPermutationsNeighborhood::Tag()
{
    return "(N)All_Permutations";
}
