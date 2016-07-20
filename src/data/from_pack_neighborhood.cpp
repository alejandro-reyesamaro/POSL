#include "from_pack_neighborhood.h"
#include "dStrategy/standard_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>

std::vector<int> InitConfiguration(int * pack);

FromPackNeighborhood::FromPackNeighborhood(int * pack)
    : Neighborhood(InitConfiguration(pack)),
      changeAtBhv(std::make_shared<StandardApplyChangeBehavior>(pack[1]))
{    
    int conf_size = pack[1];
    pack+= conf_size + 2;
    int n_size = *pack;
    pack++;

    for(int i = 0; i < n_size; i++)
    {
        int deg = *pack;
        pack++;
        std::vector<int> new_indexes;
        std::vector<int> new_values;
        for (int j = 0; j < deg; j++)
        {
            new_indexes.push_back(*pack);
            pack++;
            new_values.push_back(*pack);
            pack++;
        }
        T_Changes next_changes = {new_indexes, new_values, deg};
        changes.push_back(next_changes);
    }
}

std::shared_ptr<POSL_Iterator> FromPackNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

std::vector<int> InitConfiguration(int * pack)
{
    std::vector<int> conf(pack[1]);
    copy(&pack[2], &pack[2] + pack[1], conf.begin());
    return conf;
}

std::shared_ptr<FactoryPacker> FromPackNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> FromPackNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
    //return applyChangeAt(index);
}

/*
vector<int> FromPackNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    return configuration_changed;
}
*/
