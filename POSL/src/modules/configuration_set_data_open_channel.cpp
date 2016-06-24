#include "configuration_set_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

ConfigurationSetDataOpenChannel::ConfigurationSetDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      aux_conf(_bench->Dimension(), 0)
{
    received_data = make_shared<ConfigurationSet>();
}

int ConfigurationSetDataOpenChannel::dataID()
{
    return CONFIGURATION_SET_PACKING_ID;
}

string ConfigurationSetDataOpenChannel::codeToSend()
{
    return string(OCH_CONFIGURATION_SET_TOK) + "(" + name + ")";
}

std::shared_ptr<ConfigurationSet> ConfigurationSetDataOpenChannel::cast_to_configuration_set()
{
    return static_pointer_cast<ConfigurationSet>(received_data);
}

void ConfigurationSetDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    std::copy(buffer + 2, buffer + 2 + aux_conf.size(), aux_conf.begin());
    cast_to_configuration_set()->addElement(aux_conf);
}

shared_ptr<ComputationData> ConfigurationSetDataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        cast_to_configuration_set()->clearAll();
        return received_data;
    }
    else return nullptr;
}
