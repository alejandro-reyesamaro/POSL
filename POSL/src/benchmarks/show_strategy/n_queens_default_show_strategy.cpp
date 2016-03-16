#include "n_queens_default_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

NQueensDefaultShowStrategy::NQueensDefaultShowStrategy(int n)
    : N(n)
{}

string NQueensDefaultShowStrategy::showSolution(std::shared_ptr<Solution> solution)
{
    if(N > 20)
        return Tools::int2str(N) +"-Queens: " + solution->configurationToString();

    std::string out = "";
    std::vector<int> config = solution->get_conf_by_copy();

    // TRANSPOSING
    std::vector<int> T(N,0);
    for(std::vector<int>::iterator it = config.begin(); it != config.end(); ++it)
        T[*it] = *it;
    //------------

    for(std::vector<int>::iterator it = config.begin(); it != config.end(); ++it)
    {
        int pos = *it;
        for(int i = 0; i < N; i ++)
            out +=(i != pos)? "0 " : "X ";
        out += "\n";
    }
    return out;
}
