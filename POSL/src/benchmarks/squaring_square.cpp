#include "squaring_square.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../tools/tools.h"

SquaringSquare::SquaringSquare(int _size, vector<int> _squares)
    : Benchmark(vector<Domain>(_squares.size() * 2, Domain(new Factory_NIntDomain(0,_size - 1)))),
      size(_size),
      squares(_squares)
{}

int SquaringSquare::solutionCost(vector<int> configuration)
{
    int sqrs = squares.size();
    if (configuration.size() > sqrs * 2)
        return size * size * size;

    int cost = 0;
    int penaltyX = 0, penaltyY = 0;

    for(int i = 0; i < sqrs -1; i++)
        for(int j = i + 1; j < sqrs; j++)
        {
            int intersecX = Tools::segmentIntersection(configuration[i], configuration[i]+squares[i], configuration[j], configuration[j]+squares[j]);
            int intersecY = Tools::segmentIntersection(configuration[i+sqrs], configuration[i+sqrs]+squares[i], configuration[j+sqrs], configuration[j+sqrs]+squares[j]);
            // if the i-th square does not fit into the Square
            penaltyX = max(0, configuration[i]+squares[i] - size);
            penaltyY = max(0, configuration[i+sqrs]+squares[i] - size);
            // if the j-th square does not fit into the Square
            penaltyX += max(0, configuration[j]+squares[j] - size);
            penaltyY += max(0, configuration[j+sqrs]+squares[j] - size);

            cost += intersecX * intersecY + penaltyX + penaltyY;
        }
    return cost;
}

int SquaringSquare::Size(){ return size; }

int SquaringSquare::SquareAt(int pos){ return (pos >= 0 && pos < size)? squares[pos] : -1; }

string SquaringSquare::ShowSolution(Solution * solution)
{
    string out = "";
    vector<int> conf = solution->GetConfiguration();
    int n = squares.size();
    out += "(" + Tools::int2str(conf[0]) + ";" + Tools::int2str(conf[n]) + ")";
    for(int i = 1; i < n; i++)
        out += ", (" + Tools::int2str(conf[i]) + ";" + Tools::int2str(conf[i+n]) + ")";
    return out;
}
