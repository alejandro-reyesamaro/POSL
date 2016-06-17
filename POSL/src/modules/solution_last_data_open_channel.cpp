#include "solution_last_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

SolutionLastDataOpenChannel::SolutionLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      solution_data(make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension()))
{}

int SolutionLastDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionLastDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_LAST_TOK) + "(" + name + ")";
}

shared_ptr<ComputationData> SolutionLastDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    solution_data->UpdateConfigurationFromPack(buffer);
    //cout << solution_data->get_conf_by_ref().size() << endl;
    return solution_data;
}
