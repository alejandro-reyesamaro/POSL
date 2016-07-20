#include "om_default_processing.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_DefaultProcessing::OM_DefaultProcessing()
{}

shared_ptr<Solution> OM_DefaultProcessing::spcf_execute(shared_ptr<PSP>, shared_ptr<Solution> input)
{
    return input;
}

string OM_DefaultProcessing::codeToSend()
{
    return OM_DEFAULT_PROCESSING_TOK;
}

string OM_DefaultProcessing::Tag()
{
    return "Default_Rearrangement";
}
