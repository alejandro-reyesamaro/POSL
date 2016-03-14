#include "solution.h"
#include "../tools/tools.h"
#include "../packing/factory/factory_solution_packer.h"

#include <iostream>

Solution::Solution(std::vector<Domain> _domains)
    : domains(_domains),
      configuration(_domains.size(), 0)
{}

Solution::Solution(std::vector<Domain> _domains, std::vector<int> conf)
    : domains(_domains),
      configuration(conf)
{}

void Solution::UpdateConfiguration(std::vector<int> new_config)
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

bool Solution::equal(std::shared_ptr<Solution> other)
{
    return Tools::equals_vectors(other->configuration, configuration);
    /*
    if (other->configuration.size() != configuration.size())
        return false;
    for(unsigned int i = 0; i < configuration.size(); i++)
        if (other->configuration[i] != configuration[i])
            return false;
    return true;
    */
}

std::string Solution::configurationToString(){ return Tools::configurationToString(configuration); }

std::shared_ptr<FactoryPacker> Solution::BuildPacker(){ return std::make_shared<FactorySolutionPacker>(shared_from_this()); }
