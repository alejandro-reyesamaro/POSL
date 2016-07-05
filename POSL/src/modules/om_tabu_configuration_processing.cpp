#include "om_tabu_configuration_processing.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_TabuConfigurationProcessing::OM_TabuConfigurationProcessing()
{}

shared_ptr<Solution> OM_TabuConfigurationProcessing::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{    
    //cout << "om_tabu_processing.cpp ..." << endl;
    if (input != nullptr)
    {
        //cout << "om_tabu_processing.cpp input size: " << input->get_conf_by_ref().size() << endl;
        //if(psp->GetPID() == 1)
        //    cout << "om_tabu_processing.cpp tabu size: " << psp->GetTabuObject()->GetTabuSize() << endl;
        psp->GetTabuObject()->addTabuSolution(input->get_conf_by_ref());
    }
    return input;
}

string OM_TabuConfigurationProcessing::codeToSend()
{
    return OM_TABU_CONFIGURATION_PROCESSING_TOK; //"OM_R.Tabu"
}

string OM_TabuConfigurationProcessing::Tag()
{
    return "Tabu_Configuration_Processing";
}
