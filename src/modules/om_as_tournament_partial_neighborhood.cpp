#include "om_as_tournament_partial_neighborhood.h"
#include "../tools/tokens_definition.h"

#include <iostream>
using namespace std;

OM_ASTournamentPartialNeighborhood::OM_ASTournamentPartialNeighborhood(std::shared_ptr<Benchmark> bench,
                                                                       int _players,
                                                                       int _groups,
                                                                       int _part)
    : V(make_shared<ASTournamentPartialNeighborhood>(bench, bench->Dimension(), _players, _groups, _part))
{}

shared_ptr<Neighborhood> OM_ASTournamentPartialNeighborhood::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{
    V->Init(psp, input->get_conf_by_ref());
    //cout << "OM_V" << endl;
    return V;
}

string OM_ASTournamentPartialNeighborhood::codeToSend()
{
    return OM_TOURNAMENT_PARTIAL_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK;// "OM_V.TournPartialWeek"
}

string OM_ASTournamentPartialNeighborhood::Tag()
{
    return "(N)Tournament_PartialASSwap";
}
