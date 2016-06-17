#include "om_tabu_processing.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_TabuProcessing::OM_TabuProcessing()
{}

shared_ptr<Solution> OM_TabuProcessing::spcf_execute(shared_ptr<PSP> psp, shared_ptr<Solution> input)
{    
    if (input != nullptr)
    {
        //cout << "om_tabu_processing.cpp input size: " << input->get_conf_by_ref().size() << endl;
        psp->GetTabuObject()->addTabuSolution(input->get_conf_by_ref());
    }
    return input;
}

string OM_TabuProcessing::codeToSend()
{
    return OM_TABU_PROCESSING_TOK; //"OM_R.Tabu"
}

string OM_TabuProcessing::Tag()
{
    return "Tabu_Processing";
}
