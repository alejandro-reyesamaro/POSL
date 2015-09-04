#include "solution.h"
#include "../tools/tools.h"
#include "../packing/factory/factory_solution_packer.h"

#include <iostream>

Solution::Solution(vector<Domain> _domains)
    : domains(_domains),
      configuration(_domains.size(), 0)
{
}

Solution::Solution(vector<Domain> _domains, vector<int> conf)
    : domains(_domains),
      configuration(conf)
{
}

void Solution::UpdateConfiguration(vector<int> new_config)
{
    if(new_config.size() != configuration.size())
        throw "(POSL Exception) Configurations sizes missmatch (Solution::UpdateConfiguration)";
    copy(new_config.begin(), new_config.end(), configuration.begin());
}

void Solution::UpdateConfigurationFromPack(int * pack)
{
    copy(pack + 2, pack + 2 + configuration.size(), configuration.begin());
}

bool Solution::equal(Solution * other)
{
    if (other->configuration.size() != configuration.size())
        return false;
    for(unsigned int i = 0; i < configuration.size(); i++)
        if (other->configuration[i] != configuration[i])
            return false;
    return true;
}

string Solution::configurationToString(){ return Tools::configurationToString(configuration); }

FactoryPacker * Solution::BuildPacker(){ return new FactorySolutionPacker(this); }
