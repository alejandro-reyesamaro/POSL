#include "om_default_rearrange.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

OM_DefaultRearrange::OM_DefaultRearrange()
{}

shared_ptr<Solution> OM_DefaultRearrange::spcf_execute(shared_ptr<PSP>, shared_ptr<Solution> input)
{
    return input;
}

string OM_DefaultRearrange::codeToSend()
{
    return OM_DEFAULT_REARRANGEMENT_TOK;
}

string OM_DefaultRearrange::Tag()
{
    return "Default_Rearrangement";
}
