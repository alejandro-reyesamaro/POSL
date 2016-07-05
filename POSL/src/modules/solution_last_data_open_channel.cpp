#include "solution_last_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

SolutionLastDataOpenChannel::SolutionLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      received_data(make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension()))
{}

int SolutionLastDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionLastDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_LAST_TOK) + "(" + name + ")";
}

/*
std::shared_ptr<Solution> SolutionLastDataOpenChannel::cast_to_solution()
{
    return static_pointer_cast<Solution>(received_data);
}
*/

void SolutionLastDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    received_data->UpdateConfigurationFromPack(buffer);
    //cout << solution_data->get_conf_by_ref().size() << endl;
}

shared_ptr<ComputationData> SolutionLastDataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        return received_data;
    }
    else return nullptr;
}
