#include "om_best_improvement_tabu_selection.h"

#include <iostream>
using namespace std;

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection()
    : search_strategy(new NeighborSelectingBestImprovementTabu())
{}

ComputationData * OM_BestImprovementTabuSelection::execute(PSP *psp, ComputationData * input)
{
    //cout << "Inside OM Best Impro TABU" << endl;
    DecisionPair * result = search_strategy->select(psp, (Neighborhood *)input);
    //cout << "Inside OM Best Impro TABU - DONE" << endl;
    return result;
}

string OM_BestImprovementTabuSelection::codeToSend()
{
    return "C4";
}
