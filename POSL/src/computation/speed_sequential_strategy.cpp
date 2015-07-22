#include "speed_sequential_strategy.h"
#include "../data/neighborhood.h"
#include "../data/union_neighborhood.h"
#include "../tools/chronometer.h"

#include <iostream>

SpeedSequentialStrategy::SpeedSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * SpeedSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    Chronometer * chro = new Chronometer();
    chro->start();
    Neighborhood * v1 = (Neighborhood *)M1->execute(psp, input);
    chro->stop();
    int time1 = chro->TimeMiliseconds();
    chro->reset();
    chro->start();
    Neighborhood * v2 = (Neighborhood *)M2->execute(psp, input);
    chro->stop();
    int time2 = chro->TimeMiliseconds();
    return (time1 <= time2) ? v1 : v2;
}
