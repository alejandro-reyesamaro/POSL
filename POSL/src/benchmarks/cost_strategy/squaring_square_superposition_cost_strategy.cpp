#include "squaring_square_superposition_cost_strategy.h"
#include "../../tools/tools.h"

SquaringSquareSuperpositionCostStrategy::SquaringSquareSuperpositionCostStrategy(int _size, std::vector<int> &_squares)
    : size(_size),
      squares(_squares)
{}

int SquaringSquareSuperpositionCostStrategy::solutionCost(std::vector<int> & configuration)
{
    int sqrs = squares.size();
    if (configuration.size() > sqrs * 2)
        throw "(POSL Exception) wrong configuration length (SquaringSquareSuperpositionCostStrategy::solutionCost)";

    int cost = 0;
    int penaltyX = 0, penaltyY = 0;

    for(int i = 0; i < sqrs -1; i++)
        for(int j = i + 1; j < sqrs; j++)
        {
            int intersecX = Tools::segmentIntersection(configuration[i], configuration[i]+squares[i], configuration[j], configuration[j]+squares[j]);
            int intersecY = Tools::segmentIntersection(configuration[i+sqrs], configuration[i+sqrs]+squares[i], configuration[j+sqrs], configuration[j+sqrs]+squares[j]);
            // if the i-th square does not fit into the Square
            penaltyX = std::max(0, configuration[i]+squares[i] - size);
            penaltyY = std::max(0, configuration[i+sqrs]+squares[i] - size);
            // if the j-th square does not fit into the Square
            penaltyX += std::max(0, configuration[j]+squares[j] - size);
            penaltyY += std::max(0, configuration[j+sqrs]+squares[j] - size);

            cost += intersecX * intersecY + penaltyX + penaltyY;
        }
    return cost;
}
