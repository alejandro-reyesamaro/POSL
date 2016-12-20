#include "oms_time_counter.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"

#include <iostream>
using namespace std;

OMS_TimeCounter::OMS_TimeCounter() :
    chrono(make_shared<Chronometer>())
    , milisecs_count(0) // coment to not log
{
    chrono->reset();        
}

shared_ptr<ComputationData> OMS_TimeCounter::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    if(!chrono->isRunning())
    {
        chrono->start();
        milisecs_count = 0;
    }
    else
    {
        psp->UpdateTime(chrono->TimeMiliseconds());
        //! <debuging>
        int m = chrono->TimeMiliseconds()/10;
        if(m > milisecs_count)
        {
            milisecs_count = m;
            //string text2 = Tools::int2str(psp->CurrentCost());
            //cout << m << " - " << text2 << endl;
        }
        //! </debuging>
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
