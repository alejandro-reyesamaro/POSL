#include "tester_far_random_conf_generation.h"
#include "../data/solution.h"
#include "../modules/strategy/far_random_configuration_generation_strategy.h"
#include "../tools/tools.h"
#include "../data/uniform_domain.h"

#include <algorithm>

Tester_FarRandomConfGeneration::Tester_FarRandomConfGeneration(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_FarRandomConfGeneration::test()
{
    shared_ptr<Randomizer> rand(make_shared<Randomizer>(5, 1));
    vector<std::vector<int>> existing_confs;
    existing_confs.push_back({1, 1, 1, 2, 2});
    existing_confs.push_back({2, 2, 3, 4, 4});
    existing_confs.push_back({3, 2, 3, 2, 3});
    int min_percentage_of_changes = 60;
    shared_ptr<Domain> domain(make_shared<UniformDomain>(1,5));

    FarRandomConfigurationGenerationStrategy f(5, domain->GetValues(0));

    vector<int> new_conf = f.generate(rand, existing_confs, min_percentage_of_changes);
    cout << Tools::configurationToString(new_conf) << endl;
    return "FAR_RandomConfGeneration: OK !";// : "FAR_RandomConfGeneration: fail :/";
}
