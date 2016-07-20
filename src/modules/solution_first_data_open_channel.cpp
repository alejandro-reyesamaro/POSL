#include "solution_first_data_open_channel.h"
#include "../packing/packers/solution_packer.h"
#include "../tools/tokens_definition.h"

using namespace std;

SolutionFirstDataOpenChannel::SolutionFirstDataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : DataOpenChannel(name, _bench),
      received_data(make_shared<Solution>(_bench->Variable_Domain(), _bench->Dimension()))
{}

int SolutionFirstDataOpenChannel::dataID()
{
    return SOLUTION_PACKING_ID;
}

string SolutionFirstDataOpenChannel::codeToSend()
{
    return string(OCH_SOLUTION_FIRST_TOK) + "(" + name + ")";
}

/*
std::shared_ptr<Solution> SolutionFirstDataOpenChannel::cast_to_solution()
{
    return static_pointer_cast<Solution>(received_data);
}
*/

void SolutionFirstDataOpenChannel::storeMessage(int * buffer, std::shared_ptr<PSP>)
{
    if(!contains_information)
        received_data->UpdateConfigurationFromPack(buffer);
}

shared_ptr<ComputationData> SolutionFirstDataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        return received_data;
    }
    else return nullptr;
}
