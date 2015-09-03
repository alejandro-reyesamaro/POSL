#include "om_best_improvement_tabu_selection.h"

#include <iostream>
using namespace std;

OM_BestImprovementTabuSelection::OM_BestImprovementTabuSelection(Benchmark * bench)
    : search_strategy(new NeighborSelectingBestImprovementTabu(bench->Domains()))
{}

DecisionPair * OM_BestImprovementTabuSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    return search_strategy->select(psp, input);
}

string OM_BestImprovementTabuSelection::codeToSend()
{
    return "C4";
}
