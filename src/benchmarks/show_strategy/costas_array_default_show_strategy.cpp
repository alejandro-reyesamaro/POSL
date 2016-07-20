#include "costas_array_default_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

CostasArrayDefaultShowStrategy::CostasArrayDefaultShowStrategy(int n)
    : N(n)
{}

string write_limit(int N)
{
    string out = "";
    for(int i = 0; i < N; i++)
        out += "+-";
    out += "+\n";
    return out;
}

string write_line(int N, int pos)
{
    string out = "";
    for(int i = 0; i < N; i ++)
        out +=(i != pos)? "| " : "|*";
    out += "|\n";
    return out;
}

string CostasArrayDefaultShowStrategy::showSolution(std::shared_ptr<Solution> solution)
{
    if(N > 24)
        return Tools::int2str(N) +"-Costas Array: " + solution->configurationToString();

    std::string out = Tools::int2str(N) +"-Costas Array: " + solution->configurationToString() + "\n";
    std::vector<int> config = solution->get_conf_by_copy();

    out += write_limit(N);
    for(std::vector<int>::iterator it = config.begin(); it != config.end(); ++it)
    {
        int pos = *it;        
        out += write_line(N, pos);
    }
    out += write_limit(N);
    return out;
}
