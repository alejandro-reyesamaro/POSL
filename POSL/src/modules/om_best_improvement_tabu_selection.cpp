#include "om_best_improvement_tabu_selection.h"

#include <iostream>
using namespace std;

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection()
    : search_strategy(new NeighborSelectingBestImprovementTabu())
{}

DecisionPair * OM_BestImprovementTabuSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    DecisionPair * result = search_strategy->select(psp, input);
    return result;
}

string OM_BestImprovementTabuSelection::codeToSend()
{
    return "C4";
}
