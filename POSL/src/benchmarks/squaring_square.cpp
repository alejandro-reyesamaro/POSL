#include "squaring_square.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../tools/tools.h"
#include "cost_strategy/squaring_square_superposition_cost_strategy.h"
#include "show_strategy/squaring_square_default_show_strategy.h"
#include "relative_cost_strategy/squaring_square_relative_cost_strategy.h"

using namespace std;

SquaringSquare::SquaringSquare(int _size, std::vector<int> _squares)
    : Benchmark(std::vector<Domain>(_squares.size() * 2, Domain(std::make_shared<Factory_NIntDomain>(0,_size - 1))),
                make_shared<SquaringSquareSuperpositionCostStrategy>(_size, _squares),
                make_shared<SquaringSquareRelativeCostStrategy>(),
                make_shared<SquaringSquareDefaultShowStrategy>(_squares.size())),
      size(_size),
      squares(_squares)
{}

string SquaringSquare::showInstance()
{
    string out =  "Squaring Square: size-" + Tools::int2str(size);
           out += ", Squares: \n  >>[ ";
    for(int i = 0; i < squares.size(); i ++)
        out+= Tools::int2str(squares[i]) + " ";
    out += "]\n";
    return out;
}
