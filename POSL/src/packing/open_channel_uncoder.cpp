#include "open_channel_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/solution_data_open_channel.h"
#include "../modules/decision_pair_data_open_channel.h"
#include "../modules/neighborhood_data_open_channel.h"

using namespace std;

OpenChannelUncoder::OpenChannelUncoder()
{
}

std::shared_ptr<OpenChannel> OpenChannelUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    //pair<string, string> p = CodingTools::extractOChTokenAndName(code);
    pair<pair<string, string>, string> p_tnm = CodingTools::separateTokenAndCode(code);
    string och_token_name = p_tnm.first.second;
    pair<string, string> p = CodingTools::extractInnerCode(p_tnm.second, "(", ")", false, true);
    string och_name = p.first;

    if(och_token_name == OCH_SOLUTION_TOK_NAME) // SOLUTION
        return make_shared<SolutionDataOpenChannel>(och_name, bench);
    else if(och_token_name == OCH_NEIGHBORHOOD_TOK_NAME) // NEIGHBORHOOD
        return make_shared<NeighborhoodDataOpenChannel>(och_name, bench);
    else if(och_token_name == OCH_DECISIONPAIR_TOK_NAME) // DECISION PAIR
        return make_shared<DecisionPairDataOpenChannel>(och_name, bench);
    else
        throw "(POSL Exception) Not well coded Open CHannel (OpenChannelUncoder::uncode)";
}
