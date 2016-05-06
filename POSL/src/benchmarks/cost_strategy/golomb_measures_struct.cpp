#include "golomb_measures_struct.h"

using namespace std;

vector<list<int>> create(int size)
{
    vector<list<int>> v_result;
    for(int i = 0; i <= size - 1; i++)
    {
        list<int> l;
        v_result.push_back(l);
    }
    return v_result;
}

GolombMeasuresStruct::GolombMeasuresStruct(int size)
    : measures(create(size))
{
}


void GolombMeasuresStruct::clear()
{
    for(int var = 0; var < measures.size(); var++)
        measures[var].clear();
}

void GolombMeasuresStruct::addVariableDistance(int variable_index, int distance)
{
    measures[variable_index].push_back(distance);
}

void GolombMeasuresStruct::removeDistanceFromVariable(int variable_index, int distance)
{
    measures[variable_index].remove(distance);
}

int GolombMeasuresStruct::measuresOfVariable(int variable_index)
{
    aux_measures = measures[variable_index];
    aux_measures.unique();
    return aux_measures.size();
}
