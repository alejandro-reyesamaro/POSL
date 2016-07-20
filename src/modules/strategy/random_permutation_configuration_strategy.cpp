#include "random_permutation_configuration_strategy.h"
#include "../../tools/tools.h"

using namespace std;

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy(int N)
    : config(Tools::generateMonotony(N))
{}

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy(int a, int b)
    : config(Tools::generateMonotony(a, b))
{}

std::vector<int> RandomPermutationConfigurationStrategy::generate(shared_ptr<Randomizer> rand)
{
    rand->vector_shuffle(config);
    return config;
}
