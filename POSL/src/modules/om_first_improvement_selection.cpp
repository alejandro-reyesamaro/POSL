#include "om_first_improvement_selection.h"

#include <iostream>
using namespace std;

OM_FirstImprovementSelection::OM_FirstImprovementSelection(Benchmark * bench)
    : search_strategy(new NeighborSelectingFirstImprovement(bench->Domains()))
{}

DecisionPair * OM_FirstImprovementSelection::spcf_execute(PSP * psp, Neighborhood * input)
{
    return search_strategy->select(psp, input);
}

string OM_FirstImprovementSelection::codeToSend()
{
    return "C2";
}
