#include "squaring_square_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define Z _squares.size()

vector<int> store_movement_capacity(vector<int> _squares, int _size)
{
    vector<int> mc(Z);
    for(unsigned int i = 0; i < Z; i++)
        mc[i] = (_size * _size) / (_squares[i] * _squares[i]);
    return mc;
}

SquaringSquareCostStructure::SquaringSquareCostStructure(int _size, vector<int> _squares)
    : Size(_size),
      CurrentCost(-1),
      Configuration(Z * 2),
      squares(_squares),
      m_cost(Z),
      cost_on_variable_coefix(Z, 0),
      cost_on_leaving(Z, 0),
      momement_capacity(store_movement_capacity(_squares, _size))
{}

void SquaringSquareCostStructure::set(std::vector<int> & _configuration)
{
    //copy(_configuration.begin(), _configuration.end(), Configuration.begin());
    Configuration = _configuration;
    fill(cost_on_variable_coefix.begin(), cost_on_variable_coefix.end(), 0);
    fill(cost_on_leaving.begin(), cost_on_leaving.end(), 0);
    CurrentCost = 0;
    int sqrs = squares.size();
    int intersecX, intersecY, penaltyX, penaltyY;
    for(int i = 0; i < sqrs -1; i++)
    {
        for(int j = i + 1; j < sqrs; j++)
        {
            intersecX = Tools::segmentIntersection(Configuration[i], Configuration[i]+squares[i], Configuration[j], Configuration[j]+squares[j]);
            intersecY = Tools::segmentIntersection(Configuration[i+sqrs], Configuration[i+sqrs]+squares[i], Configuration[j+sqrs], Configuration[j+sqrs]+squares[j]);
            m_cost.set(i,j, intersecX * intersecY);                 // Intersection square_i and square_j
            cost_on_variable_coefix[i] += intersecX * intersecY;    // Projected cost of square i
            cost_on_variable_coefix[j] += intersecX * intersecY;    // Projected cost of square i
        }

        penaltyX = std::max(0, Configuration[i]+squares[i] - size);
        penaltyY = std::max(0, Configuration[i+sqrs]+squares[i] - size);
        cost_on_leaving[i] = penaltyX * penaltyY;                   // Cost on leaving the big square (square i)

        CurrentCost += (cost_on_variable_coefix[i] + (cost_on_leaving[i] * cost_on_leaving[i])) * momement_capacity[i];
    }
}

int SquaringSquareCostStructure::relative_cost(std::vector<int> & new_config, T_Changes change, bool updating)
{
    throw "(POSL Exception) not implemented yet (SquaringSquareCostStructure::relative_cost)";
}
