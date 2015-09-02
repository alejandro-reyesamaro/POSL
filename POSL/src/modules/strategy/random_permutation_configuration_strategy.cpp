#include "random_permutation_configuration_strategy.h"
#include "../../tools/tools.h"

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy(int N)
    : config(Tools::generateMonotony(N))
{}

vector<int> RandomPermutationConfigurationStrategy::generate()
{
    Tools::shuffle(config);
    return config;
}
