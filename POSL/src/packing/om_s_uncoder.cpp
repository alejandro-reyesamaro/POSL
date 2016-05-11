#include "om_s_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_random_conf_ordered_generation.h"
#include "../modules/om_random_permutation_generation.h"
#include "../modules/om_golomb_valid_generation.h"

using namespace std;

OM_S_Uncoder::OM_S_Uncoder()
{
}

shared_ptr<OperationModule> OM_S_Uncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    //int pos_point = code.find('.');
    //string om_name = code.substr(pos_point + 1, code.find(' ') - pos_point + 1);

    if(code == OM_FIXED_FIRST_CONFIGURATION_TOK)
        return make_shared<OM_FixedFirstConfiguration>(bench);
    else if(code == OM_RANDOM_CONFIG_GENERATION_TOK)
        return make_shared<OM_RandomConfGeneration>(bench);
    else if(code == OM_RANDOM_CONFIG_ORDERED_GENERATION_TOCK)
        return make_shared<OM_RandomConfOrderedGeneration>(bench);
    else if(code == OM_RANDOM_CONFIG_PERMUTATION_BY_BLOCKS_TOK)
        return make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench);
    else if(code == OM_RANDOM_CONFIG_GOLOMB_VALID_TOK)
        return make_shared<OM_GolombValidGeneration>(bench);
    else if(code == OM_RANDOM_PERMUTATION_GENERATION_TOK)
        return make_shared<OM_RandomPermutationGeneration>(bench);
    else
        throw "(POSL Exception) OM does not exist (OM_S_Uncoder::uncode)";
}
