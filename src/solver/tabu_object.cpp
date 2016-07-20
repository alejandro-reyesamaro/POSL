#include "tabu_object.h"
#include "../tools/tools.h"

#include <iostream>

using namespace std;

function<float(vector<int>&, vector<int>&)> get_norm_function(int norm)
{
    switch (norm)
    {
        case 1:
            return Tools::norm1;
        case 2:
            return Tools::norm2;
        case 8:
            return Tools::norm8;
        default:
            throw "(POSL Exception) No norm defined (tabu_object.cpp)";
    }
}

TabuObject::TabuObject(int problem_dimention, int _tabu_size, float _eps, int _norm)
    : tabu_list(make_shared<TabuList>(_tabu_size)),
      last_arrived_tabu_configuration(problem_dimention, 0),
      something_has_arrived(false),
      eps(_eps),
      norm(_norm),
      tabu_size(_tabu_size),
      norm_function(get_norm_function(_norm))
{}

void TabuObject::addTabuSolution(vector<int> & configuration)
{
    //cout << "tabu_object.cpp input size: " << configuration.size() << endl;
    something_has_arrived = true;
    tabu_list->push(configuration);
    copy(configuration.begin(), configuration.end(), last_arrived_tabu_configuration.begin());
}

bool TabuObject::isGlobalNeighborTabu(vector<int> & configuration)
{
    return tabu_list->isTabuByNorm(configuration, eps, norm_function);
}

bool TabuObject::isGlobalTabu(vector<int> & configuration)
{
    return tabu_list->isTabu(configuration);
}

std::shared_ptr<ListIterator> TabuObject::GetTabusIterator()
{
    return tabu_list->GetConfigurationsIterator();
}
