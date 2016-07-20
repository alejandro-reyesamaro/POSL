#include "show_bechmark_result_strategy.h"
#include "../../tools/tools.h"

using namespace std;

ShowBechmarkResultStrategy::ShowBechmarkResultStrategy()
{
}

std::string ShowBechmarkResultStrategy::show(std::shared_ptr<PSP> psp,
                                             std::shared_ptr<Benchmark> bench,
                                             shared_ptr<Solution> best_solution,
                                             int best_cost,
                                             shared_ptr<Solution> final_solution,
                                             int final_cost,
                                             string strategy_tag,
                                             int iterations,
                                             int time)
{
    if(final_solution != nullptr && best_solution != nullptr){
        string str_finalSol = bench->ShowSolution(final_solution);
        string str_bestSol = bench->ShowSolution(best_solution);
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
        out += "Strategy: " + strategy_tag + " [id: " + Tools::int2str(psp->GetPID()) + "]";
        out += psp->FoundThanksOuterInformation() ? " (thanks!)" : "";
        return out;
    }
    else return "Solver not working";
}
