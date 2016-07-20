#include "oms_time_counter.h"
#include "../tools/tokens_definition.h"

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
    {
        psp->UpdateTime(chrono->TimeMiliseconds());
        if(psp->GetTime() > psp->GetTimeOut())
        {
            cout << "(POSL exception) cutting time" << endl;
            exit(0);
        }
    }

    //cout << "Time counted: " << psp->GetTime() << endl;
    return input;
}

string OMS_TimeCounter::codeToSend()
{
    return OMS_TIME_COUNTER_TOK;
}

string OMS_TimeCounter::Tag()
{
    return "Time counter";
}
