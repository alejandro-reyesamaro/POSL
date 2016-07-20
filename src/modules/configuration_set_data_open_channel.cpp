#include "configuration_set_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"

#include <iostream>
#include <cassert>

using namespace std;

ConfigurationSetDataOpenChannel::ConfigurationSetDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      received_data(make_shared<ConfigurationSet>()),
      arriving_conf(_bench->Dimension(), 0)
{    
}

int ConfigurationSetDataOpenChannel::dataID()
{
    // The open channel will receive one configuration N times
    return SOLUTION_PACKING_ID;
}

string ConfigurationSetDataOpenChannel::codeToSend()
{
    return string(OCH_CONFIGURATION_SET_TOK) + "(" + name + ")";
}

/*
std::shared_ptr<ConfigurationSet> ConfigurationSetDataOpenChannel::cast_to_configuration_set()
{
    assert(received_data != nullptr);
    return static_pointer_cast<ConfigurationSet>(received_data);
}
*/

void ConfigurationSetDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    //cout << "configuration_set_data_open_channel.cpp -> storing message " << endl;
    std::copy(buffer + 2, buffer + 2 + arriving_conf.size(), arriving_conf.begin());
    //cout << Tools::configurationToString(aux_conf) << endl;
    //cast_to_configuration_set()->addElement(arriving_conf);
    //aux_conf_set1->addElement(aux_conf);
    configutrations.push_back(arriving_conf);
}

shared_ptr<ComputationData> ConfigurationSetDataOpenChannel::selectMessage()
{
    //cout << "configuration_set_data_open_channel.cpp -> selecting message " << endl;
    if (contains_information)
    {
        contains_information = false;
        //aux_conf_set = static_pointer_cast<ConfigurationSet>(received_data);//cast_to_configuration_set();
        //assert(aux_conf_set1 != nullptr);
        received_data = make_shared<ConfigurationSet>(configutrations);
        configutrations.clear();
        //aux_conf_set2 = aux_conf_set1;
        //aux_conf_set1  = make_shared<ConfigurationSet>();
        //cout << "configuration_set_data_open_channel.cpp -> message selected " << received_data->size() << endl;
        return received_data;// aux_conf_set;
    }
    else
    {
        //cout << "configuration_set_data_open_channel.cpp -> nothing " << endl;
        return nullptr;
    }
}
