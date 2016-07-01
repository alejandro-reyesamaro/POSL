#include "om_tabu_configuration_set_processing.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_TabuConfigurationSetProcessing::OM_TabuConfigurationSetProcessing()
{}

shared_ptr<ConfigurationSet> OM_TabuConfigurationSetProcessing::spcf_execute(shared_ptr<PSP> psp, shared_ptr<ConfigurationSet> input)
{
    cout << "om_tabu_configuration_set_processing.cpp .... " <<  endl;
    if (input != nullptr)
    {
        cout << "om_tabu_configuration_set_processing.cpp input size: " << input->size() << endl;

        it = input->getIterator();
        it->Reset();
        while(it->SomeNext())
        {
            config = it->GetNext();
            psp->GetTabuObject()->addTabuSolution(config);
        }
    }
    return input;
}

string OM_TabuConfigurationSetProcessing::codeToSend()
{
    return OM_TABU_CONFIGURATION_SET_PROCESSING_TOK;
}

string OM_TabuConfigurationSetProcessing::Tag()
{
    return "Tabu_Configuration_Set_Processing";
}
