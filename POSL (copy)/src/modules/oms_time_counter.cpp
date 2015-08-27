#include "oms_time_counter.h"

#include <iostream>
using namespace std;

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

    //cout << "Time counted: " << psp->GetTime() << endl;
    return input;
}

string OMS_TimeCounter::codeToSend()
{
    return "S1";
}
