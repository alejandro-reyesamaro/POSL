#include "open_channel_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/solution_last_data_open_channel.h"
#include "../modules/solution_first_data_open_channel.h"
#include "../modules/decision_pair_last_data_open_channel.h"
#include "../modules/decision_pair_first_data_open_channel.h"
#include "../modules/neighborhood_last_data_open_channel.h"

using namespace std;

OpenChannelUncoder::OpenChannelUncoder()
{
}

std::shared_ptr<OpenChannel> OpenChannelUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    pair<pair<string, string>, string> p_tnm = CodingTools::separateTokenAndCode(code);
    string och_token_name = p_tnm.first.second;
    pair<string, string> p = CodingTools::extractInnerCode(p_tnm.second, "(", ")", false, true);
    string och_name = p.first;

    if(och_token_name == OCH_SOLUTION_FIRST_TOK_NAME) // SOLUTION
        return make_shared<SolutionFirstDataOpenChannel>(och_name, bench);
    if(och_token_name == OCH_SOLUTION_LAST_TOK_NAME) // SOLUTION
        return make_shared<SolutionLastDataOpenChannel>(och_name, bench);
    else if(och_token_name == OCH_NEIGHBORHOOD_LAST_TOK_NAME) // NEIGHBORHOOD
        return make_shared<NeighborhoodLastDataOpenChannel>(och_name, bench);
    else if(och_token_name == OCH_DECISIONPAIR_FIRST_TOK_NAME) // DECISION PAIR
        return make_shared<DecisionPairFirstDataOpenChannel>(och_name, bench);
    else if(och_token_name == OCH_DECISIONPAIR_LAST_TOK_NAME) // DECISION PAIR
        return make_shared<DecisionPairLastDataOpenChannel>(och_name, bench);
    else
        throw "(POSL Exception) Not well coded Open CHannel (OpenChannelUncoder::uncode)";
}
