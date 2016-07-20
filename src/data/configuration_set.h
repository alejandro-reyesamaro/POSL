#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "../solver/psp.h"

#define CONFIGURATION_SET_PACKING_ID 658205
#define TAGCONFIGURATIONSET "cd_CS"

class ConfigurationSet : public ComputationData, public std::enable_shared_from_this<ConfigurationSet>
{
    friend class ConfigurationSetIterator;
    public:
        ConfigurationSet();
        ConfigurationSet(std::vector<std::vector<int> > & config_set);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size(){ return configurations.size(); }
        std::vector<int> elementAt(int index);
        void addElement(std::vector<int> & new_config);
        void clearAll();

        std::shared_ptr<FactoryPacker> BuildPacker();
        std::string Tag() { return TAGCONFIGURATIONSET; }
        int comapareTo(shared_ptr<ComputationData> other, function<int(shared_ptr<ComputationData>)>);

    private:
        std::vector<std::vector<int>> configurations;
};
