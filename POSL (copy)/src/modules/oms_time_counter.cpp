#include "oms_time_counter.h"


OMS_TimeCounter::OMS_TimeCounter() : chrono(new Chronometer())
{
    chrono->reset();
}

ComputationData * OMS_TimeCounter::execute(PSP *psp, ComputationData * input)
{
    if(!chrono->isRunning())
        chrono->start();
    else
        psp->UpdateTime(chrono->TimeMiliseconds());
    return input;
}

string OMS_TimeCounter::codeToSend()
{
    return "S1";
}
