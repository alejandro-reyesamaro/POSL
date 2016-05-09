#include "golomb_tools.h"

using namespace std;

int GolombTools::max_posible_distances(int order, int length)
{
    return length - ((order - 2)*(order - 1)/2);
}

vector<int> GolombTools::vector_possible_values_to_hold_sorted(unsigned int index, std::vector<int> & current_configuration)
{
    vector<int> posible_values;
    if(index == 0)
    {
        posible_values.push_back(0);
        return posible_values;
    }
    else if(index == current_configuration.size() - 1)
    {
        posible_values.push_back(current_configuration[current_configuration.size()-1]);
        return posible_values;
    }
    int a = current_configuration[index-1];
    int b = current_configuration[index+1];
    for(int i = a+1; i <= b-1; i++)
        if(i != current_configuration[index])
            posible_values.push_back(i);
    return posible_values;
}
