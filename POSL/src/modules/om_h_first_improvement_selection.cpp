#include "om_h_first_improvement_selection.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_HFirstImprovementSelection::OM_HFirstImprovementSelection(shared_ptr<Benchmark> bench)
    : search_strategy(std::make_shared<NeighborSelectingHeuristicFirstImprovement>(bench->Variable_Domain(), bench->Dimension()))
{}

shared_ptr<DecisionPair> OM_HFirstImprovementSelection::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input)
{
    //cout << "OM_SS..." << endl;
    //shared_ptr<DecisionPair> r = search_strategy->select(psp, input);
    //cout << "...OM_SS" << endl;
    //return r;
    return search_strategy->select(psp, input);
}

string OM_HFirstImprovementSelection::codeToSend()
{
    return OM_HEURISTIC_FIRST_IMPROVEMENT_SELECTION_TOK; // "OM_SS.HFirstImpr"
}

string OM_HFirstImprovementSelection::Tag()
{
    return "Heuristic_First_Selection";
}
