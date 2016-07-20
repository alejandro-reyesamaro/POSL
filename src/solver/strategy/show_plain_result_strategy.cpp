#include "show_plain_result_strategy.h"
#include "../../tools/tools.h"

using namespace std;

ShowPlainResultStrategy::ShowPlainResultStrategy()
{
}

std::string ShowPlainResultStrategy::show(shared_ptr<PSP> psp,
                                          shared_ptr<Benchmark>,
                                          shared_ptr<Solution> best_solution,
                                          int best_cost,
                                          shared_ptr<Solution> final_solution,
                                          int final_cost,
                                          string strategy_tag,
                                          int iterations,
                                          int time)
{
    if(final_solution != nullptr && best_solution != nullptr){
        string str_finalSol = final_solution->configurationToString();
        string str_bestSol = best_solution->configurationToString();
        string out = "Final Solution:\n";
        out += str_finalSol + "\n";
        out += "Final cost: " + Tools::int2str(final_cost) + "\n";
        out += "\n";
        out += "BEST Solution:\n";
        out += str_bestSol + "\n";
        out += "BEST cost: " + Tools::int2str(best_cost) + "\n";
        out += "\n";
        out += "Iterations: " + Tools::int2str(iterations) + "\n";
        out += "Time (milisecs): " + Tools::int2str(time) + "\n";
        out += "Strategy: " + strategy_tag;
        out += psp->FoundThanksOuterInformation() ? " (thanks!)" : "";
        return out;
    }
    else return "Solver not working";
}
