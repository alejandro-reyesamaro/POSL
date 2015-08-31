#include "solution.h"
#include "../tools/tools.h"
#include "dStrategy/solution_packing_strategy.h"

#include <iostream>

Solution::Solution(vector<Domain> _domains)
    : domains(_domains),
      configuration(_domains.size(), 0)
{
    packing_strategy = new SolutionPackingStrategy(configuration);
}

Solution::Solution(vector<Domain> _domains, vector<int> conf)
    : domains(_domains),
      configuration(conf)
{
    packing_strategy = new SolutionPackingStrategy(conf);
}

void Solution::UpdateConfiguration(vector<int> new_config)
{
    if(new_config.size() != configuration.size())
        throw "(POSL Exception) Configurations sizes missmatch (Solution::UpdateConfiguration)";
    copy(new_config.begin(), new_config.end(), configurationToString().begin());
}

vector<int> Solution::GetConfiguration(){ return configuration; }

vector<Domain> Solution::GetDomains(){ return domains; }

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

vector<int> Solution::pack(){ return packing_strategy->pack(); }

int Solution::bodySize(){ return packing_strategy->BodySize(); }

vector<int> Solution::body(){ return packing_strategy->body(); }
