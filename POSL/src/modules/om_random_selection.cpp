#include "om_random_selection.h"
#include "../data/decision_pair.h"
#include "../data/neighborhood.h"
#include "../tools/tokens_definition.h"

using namespace std;

OM_RandomSelection::OM_RandomSelection(shared_ptr<Benchmark> bench)
    : search_strategy(make_shared<NeighborSelectingRandom>(bench->Variable_Domain(), bench->Dimension()))
{}

shared_ptr<DecisionPair> OM_RandomSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    //cout << "OM_S iteration: " << psp->GetIterations() << endl;
    return search_strategy->select(psp, input);
}

string OM_RandomSelection::codeToSend()
{
    return OM_RANDOM_SELECTION_TOK;
}

string OM_RandomSelection::Tag()
{
    return "Random_selection";
}
