#include "golomb_ruler_default_show_strategy.h"

using namespace std;

GolombRulerDefaultShowStrategy::GolombRulerDefaultShowStrategy(int _order, int _length)
    : order(_order),
      length(_length)
{}

string GolombRulerDefaultShowStrategy::showSolution(std::shared_ptr<Solution> & solution)
{
    string output = "";
    if(order == 6 and length == 17) output = "(6-17:2) ";
    else if(order == 7 and length == 25) output = "(7-25:4) ";
    else if(order == 8 and length == 34) output = "(8-34:7) ";
    else if(order == 9 and length == 44) output = "(9-44:9) ";
    else if(order == 10 and length == 55) output = "(10-55:11) ";
    else if(order == 11 and length == 72) output = "(11-72:19) ";
    else if(order == 12 and length == 85) output = "(12-85:20) ";
    return output + solution->configurationToString();
}
