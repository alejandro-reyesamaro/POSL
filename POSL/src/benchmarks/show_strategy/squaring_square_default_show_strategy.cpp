#include "squaring_square_default_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

SquaringSquareDefaultShowStrategy::SquaringSquareDefaultShowStrategy(int _n_squares)
    : n_squares(_n_squares)
{}

string SquaringSquareDefaultShowStrategy::showSolution(shared_ptr<Solution> solution)
{
    std::string out = "";
    std::vector<int> conf = solution->GetConfiguration();
    out += "(" + Tools::int2str(conf[0]) + ";" + Tools::int2str(conf[n_squares]) + ")";
    for(int i = 1; i < n_squares; i++)
        out += ", (" + Tools::int2str(conf[i]) + ";" + Tools::int2str(conf[i+n_squares]) + ")";
    return out;
}
