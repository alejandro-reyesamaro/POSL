#include "random_permutation_configuration_strategy.h"
#include "../../tools/tools.h"

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy(int N)
    : config(Tools::generateMonotony(N))
{}

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy(int a, int b)
    : config(Tools::generateMonotony(a, b))
{}

std::vector<int> RandomPermutationConfigurationStrategy::generate()
{
    Tools::shuffle(config);
    return config;
}
