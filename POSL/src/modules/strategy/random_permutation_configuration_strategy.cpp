#include "random_permutation_configuration_strategy.h"
#include "../../tools/tools.h"

RandomPermutationConfigurationStrategy::RandomPermutationConfigurationStrategy()
{}

Solution * RandomPermutationConfigurationStrategy::generate(vector<Domain> domains)
{
    vector<int> vec;
    int N = domains.size();

    for(int i = 0; i < N; i++)
    {
        vec.push_back(i);
        if(i < domains[i].minimum() || i > domains[i].maximum())
            throw "(POSL Exception) not valid value (RandomPermutationConfigurationStrategy::generate)";
    }

    Tools::shuffle(vec);

    Solution * new_solution = new Solution(domains, vec);
    return new_solution;
}
