#include "show_to_collect_strategy.h"
#include "../../tools/tools.h"

using namespace std;

ShowToCollectStrategy::ShowToCollectStrategy()
{
}

std::string ShowToCollectStrategy::show(shared_ptr<PSP> psp,
                                        shared_ptr<Benchmark>,
                                        shared_ptr<Solution> best_solution,
                                        int best_cost,
                                        shared_ptr<Solution> final_solution,
                                        int,
                                        string strategy_tag,
                                        int iterations,
                                        int time)
{
    if(final_solution != nullptr && best_solution != nullptr && best_cost == 0)
        return Tools::int2str(time) + " " +
               Tools::int2str(iterations) + " " +
               strategy_tag +
               (psp->FoundThanksOuterInformation() ? " (thanks!)" : "");
    else return "Unsucceful";
}
