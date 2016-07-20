#include "om_subsum_single_permutation_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_SubsumSinglePermutationNeighborhood::OM_SubsumSinglePermutationNeighborhood(shared_ptr<Benchmark> bench)
    : object_bench(static_pointer_cast<Subsum> (bench)),
      V(make_shared<SubsumSinglePermitationNeighborhood>(bench->Dimension(), object_bench->GetN()))
{}

shared_ptr<Neighborhood> OM_SubsumSinglePermutationNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_SubsumSinglePermutationNeighborhood::codeToSend()
{
    return OM_SUBSUM_SINGLE_SWAP_NEIGHBORHOOD_TOK;
}

string OM_SubsumSinglePermutationNeighborhood::Tag()
{
    return "(N)Subsum_SingleSwap";
}
