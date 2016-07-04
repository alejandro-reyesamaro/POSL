#include "configuration_set.h"
#include "dStrategy/configuration_set_iterator.h"

#include <iostream>

using namespace std;

ConfigurationSet::ConfigurationSet()
{
}

ConfigurationSet::ConfigurationSet(std::vector<std::vector<int>> & config_set)
    : configurations(config_set)
{
}

std::shared_ptr<POSL_Iterator> ConfigurationSet::getIterator()
{
    return std::make_shared<ConfigurationSetIterator>(shared_from_this());
}

std::vector<int> ConfigurationSet::elementAt(int index)
{
    if (index < configurations.size())
        return configurations[index];
    else
        throw "(POSL Exception) Index out of bounds (ConfigurationSet::elementAt)";
}

void ConfigurationSet::addElement(std::vector<int> & new_config)
{
    configurations.push_back(new_config);
}

void ConfigurationSet::clearAll()
{
    //cout << "configuration_set.cpp ... cleaning " << endl;
    configurations.clear();
}

std::shared_ptr<FactoryPacker> ConfigurationSet::BuildPacker(){ throw "Not implemented yet"; }

int ConfigurationSet::comapareTo(shared_ptr<ComputationData> other,
                                 function<int(shared_ptr<ComputationData>)>)
{
    if(other->Tag() == TAGCONFIGURATIONSET)
    {
        int ranking_this = size();
        int ranking_other = static_pointer_cast<ConfigurationSet>(other)->size();
        int difference = ranking_this - ranking_other;
        return (difference == 0) ? 0 : difference / abs(difference);
    }
    else throw "(POSL Exception) Not compearing allowed (ConfigurationSet::comapareTo)";
}
