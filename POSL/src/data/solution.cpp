#include "solution.h"
#include "../tools/tools.h"
#include "../packing/factory/factory_solution_packer.h"

#include <iostream>

using namespace std;

Solution::Solution(shared_ptr<Domain> _domains, int dimension)
    : variables_domains(_domains),
      configuration(dimension, 0)
{}

Solution::Solution(shared_ptr<Domain> _domains, vector<int> conf)
    : variables_domains(_domains),
      configuration(conf)
{}

void Solution::UpdateConfiguration(vector<int> new_config)
{
    if(new_config.size() != configuration.size())
        throw "(POSL Exception) Configurations sizes missmatch (Solution::UpdateConfiguration)";
    //std::copy(new_config.begin(), new_config.end(), configuration.begin());
    configuration = new_config;
}

void Solution::UpdateConfigurationFromPack(int * pack)
{
    std::copy(pack + 2, pack + 2 + configuration.size(), configuration.begin());
}

bool Solution::equal(shared_ptr<Solution> other)
{
    return Tools::equals_vectors(other->configuration, configuration);
}

string Solution::configurationToString(){ return Tools::configurationToString(configuration); }

shared_ptr<FactoryPacker> Solution::BuildPacker(){ return make_shared<FactorySolutionPacker>(shared_from_this()); }
