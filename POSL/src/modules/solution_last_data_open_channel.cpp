#include "solution_last_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

SolutionLastDataOpenChannel::SolutionLastDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench)
{}

int SolutionLastDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionLastDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_LAST_TOK) + "(" + name + ")";
}

std::shared_ptr<Solution> SolutionLastDataOpenChannel::cast_to_solution()
{
    return static_pointer_cast<Solution>(received_data);
}

void SolutionLastDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    cast_to_solution()->UpdateConfigurationFromPack(buffer);
    //cout << solution_data->get_conf_by_ref().size() << endl;
}
