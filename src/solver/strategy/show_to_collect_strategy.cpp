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
    {
        string output_str = Tools::int2str(time) + " " +
               Tools::int2str(iterations) + " " +
               strategy_tag +
               (psp->FoundThanksOuterInformation() ? " (thanks!)" : "");
               //" " + Tools::int2str(psp->GetPID()) +
               //" " + Tools::int2str(psp->Restarts());//" r(" + Tools::int2str(psp->Restarts()) + ")";
#ifdef MST
        output_str += " rcv:" + Tools::int2str(psp->get_received_packages()) + " acc:" + Tools::int2str(psp->get_accepted_packages()) +
                      " t:" + Tools::int2str(psp->get_average_time_of_traveling_packages());
#endif
        return output_str;
    }
    else return "Unsucceful (" + Tools::int2str(iterations) + ")";
}
