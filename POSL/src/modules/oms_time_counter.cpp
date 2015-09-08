#include "oms_time_counter.h"

#include <iostream>
using namespace std;

OMS_TimeCounter::OMS_TimeCounter() : chrono(make_shared<Chronometer>())
{
    chrono->reset();
}

shared_ptr<ComputationData> OMS_TimeCounter::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
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
