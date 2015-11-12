#include "show_to_collect_strategy.h"
#include "../../tools/tools.h"

using namespace std;

ShowToCollectStrategy::ShowToCollectStrategy()
{
}

std::string ShowToCollectStrategy::show(std::shared_ptr<Benchmark> bench,
                 shared_ptr<Solution> best_solution,
                 int best_cost,
                 shared_ptr<Solution> final_solution,
                 int final_cost,
                 string strategy_tag,
                 int iterations,
                 int time)
{
    if(final_solution != nullptr && best_solution != nullptr && best_cost == 0)
        return Tools::int2str(time) + " " + Tools::int2str(iterations) + " " + strategy_tag;
    else return "Unsucceful";
}
