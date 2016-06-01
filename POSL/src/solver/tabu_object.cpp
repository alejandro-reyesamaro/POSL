#include "tabu_object.h"

using namespace std;

#define TABU_SIZE 15

TabuObject::TabuObject(int problem_dimention)
    : tabu_list(make_shared<TabuList>(TABU_SIZE)),
      last_arrived_tabu_configuration(problem_dimention, 0),
      something_has_arrived(false)
{
}

void TabuObject::addTabuSolution(vector<int> & configuration)
{
    something_has_arrived = true;
    tabu_list->push(configuration);
    copy(configuration.begin(), configuration.end(), last_arrived_tabu_configuration.begin());
}

bool TabuObject::isGlobalTabu(vector<int> & configuration, float eps)
{
    //bool t = tabu_list->isTabuByNorm2(configuration, eps);
    return tabu_list->isTabuByNorm2(configuration, eps);
}

bool TabuObject::isGlobalTabu(vector<int> & configuration)
{
    return tabu_list->isTabu(configuration);
}
