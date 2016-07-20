#include "squaring_square.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../tools/tools.h"
#include "cost_strategy/squaring_square_superposition_cost_strategy.h"
#include "show_strategy/squaring_square_default_show_strategy.h"
#include "cost_strategy/squaring_square_relative_cost_strategy.h"
#include "../data/uniform_domain.h"
#include "../data/irregular_domain.h"

using namespace std;

shared_ptr<IrregularDomain> create_domain_from_squares(int _size, std::vector<int> _squares)
{
    int squares_size = _squares.size();
    int dim = squares_size * 2;
    vector<int> mins(dim, 0);
    vector<int> maxs (dim);
    for(int i = 0; i < squares_size; i++)
    {
        maxs[i] = _size - _squares[i];
        maxs[i+squares_size] = _size - _squares[i];
    }
    return make_shared<IrregularDomain>(mins, maxs);
}

SquaringSquare::SquaringSquare(int _size, std::vector<int> _squares)
    : Benchmark(_squares.size() * 2,
                create_domain_from_squares(_size, _squares),
                //make_shared<UniformDomain>(0,_size - 1),
                make_shared<SquaringSquareSuperpositionCostStrategy>(_size, _squares),
                make_shared<SquaringSquareRelativeCostStrategy>(_size, _squares),
                make_shared<SquaringSquareDefaultShowStrategy>(_squares.size())),
      size(_size),
      squares(_squares)
{}

string SquaringSquare::showInstance()
{
    string out =  "Squaring Square: size-" + Tools::int2str(size);
           out += ", Squares: \n  >>[ ";
    for(unsigned int i = 0; i < squares.size(); i ++)
        out+= Tools::int2str(squares[i]) + " ";
    out += "]\n";
    return out;
}
