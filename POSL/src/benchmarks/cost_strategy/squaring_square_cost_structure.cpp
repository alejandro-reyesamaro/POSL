#include "squaring_square_cost_structure.h"

SquaringSquareCostStructure::SquaringSquareCostStructure(int _size, std::vector<int> _squares)
    : Size(_size),
      CurrentCost(-1),
      Configuration(_squares.size() * 2),
      squares(_squares),
      m_cost(_squares.size())
{
}

