#include "squaring_square.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../tools/tools.h"

SquaringSquare::SquaringSquare(int _size, vector<int> _squares)
    : size(_size), squares(_squares)
{}

vector<Domain> SquaringSquare::Domains()
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(0, size - 1);
    Domain D(fd_integers);
    vector<Domain> domains (squares.size() * 2, D);
    return domains;
}

int SquaringSquare::solutionCost(Solution * sol)
{
    int sqrs = squares.size();
    if (sol->GetConfiguration().size() > sqrs * 2)
        return size * size * size;

    vector<int> conf = sol->GetConfiguration();
    int cost = 0;
    int penaltyX = 0, penaltyY = 0;

    for(int i = 0; i < sqrs -1; i++)
        for(int j = i + 1; j < sqrs; j++)
        {
            int intersecX = Tools::segmentIntersection(conf[i], conf[i]+squares[i], conf[j], conf[j]+squares[j]);
            int intersecY = Tools::segmentIntersection(conf[i+sqrs], conf[i+sqrs]+squares[i], conf[j+sqrs], conf[j+sqrs]+squares[j]);
            // if the i-th square does not fit into the Square
            penaltyX = max(0, conf[i]+squares[i] - size);
            penaltyY = max(0, conf[i+sqrs]+squares[i] - size);
            // if the j-th square does not fit into the Square
            penaltyX += max(0, conf[j]+squares[j] - size);
            penaltyY += max(0, conf[j+sqrs]+squares[j] - size);

            cost += intersecX * intersecY + penaltyX + penaltyY;
        }
    return cost;
}

int SquaringSquare::Size()
{
    return size;
}

int SquaringSquare::SquareAt(int pos)
{
    return (pos >= 0 && pos < size)? squares[pos] : -1;
}
