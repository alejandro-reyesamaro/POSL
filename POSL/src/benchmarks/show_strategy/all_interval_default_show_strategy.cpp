#include "all_interval_default_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

AllIntervalDefaultShowStrategy::AllIntervalDefaultShowStrategy(int n)
    : N(n)
{}

string AllIntervalDefaultShowStrategy::showSolution(std::shared_ptr<Solution> solution)
{
    return "All-Intervals (" + Tools::int2str(N) + "): " + solution->configurationToString();
}
