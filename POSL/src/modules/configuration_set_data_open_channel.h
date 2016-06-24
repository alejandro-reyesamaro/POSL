#pragma once

#include "data_open_channel.h"
#include "../data/configuration_set.h"

class ConfigurationSetDataOpenChannel : public DataOpenChannel
{
    public:
        ConfigurationSetDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();

        void storeMessage(int * buffer, std::shared_ptr<PSP>);
        shared_ptr<ComputationData> selectMessage();

    private:
        std::shared_ptr<ConfigurationSet> cast_to_configuration_set();

        std::vector<int> aux_conf;
};
