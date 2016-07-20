#include "speed_parallel_strategy.h"
#include "../../tools/chronometer.h"

#include <iostream>
#include <thread>
//#include <boost/thread/thread.hpp>

SpeedParallelStrategy::SpeedParallelStrategy(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2)
    : M1(_M1), M2(_M2)
{}

shared_ptr<ComputationData> SpeedParallelStrategy::evaluate(shared_ptr<PSP>, shared_ptr<ComputationData>)
{
    throw "(POSL Exception) Not yet implemented (SpeedParallelStrategy::evaluate)";
}
