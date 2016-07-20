#include "om_one_2d_change_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_One2DChangeNeighborhood::OM_One2DChangeNeighborhood(shared_ptr<Benchmark> bench)
    : V(make_shared<One2DChangeNeighborhood>(bench))
{}

shared_ptr<Neighborhood> OM_One2DChangeNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //psp->log("Executing neighborhood function...");
    //cout << "OM_V" << endl;
    return V;
}

string OM_One2DChangeNeighborhood::codeToSend()
{
    return OM_ONE_2DCHANGE_NEIHBORHOOD_TOK;// "OM_V.2DChange"
}

string OM_One2DChangeNeighborhood::Tag()
{
    return "(N)One_2DChange";
}
