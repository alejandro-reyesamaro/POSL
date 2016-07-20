#include "golomb_tools.h"
#include "tools.h"
#include <iostream>

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

vector<int> GolombTools::subsum2golomb(vector<int> & subsum_config, int golomb_order)
{
    vector<int> golomb_config(golomb_order, 0);
    for(int i = 0; i < golomb_order - 1; i++)
        golomb_config[i+1] = golomb_config[i] + subsum_config[i];
    return golomb_config;
}

vector<int> GolombTools::golomb2subsum(vector<int> & golomb_config, int golomb_order, int golomb_length)
{
    vector<bool> values(GolombTools::max_posible_distances(golomb_order, golomb_length) + 1, false);
    vector<int> subsum_config(GolombTools::max_posible_distances(golomb_order, golomb_length), 0);
    for(int i = 0; i < golomb_order - 1; i++)
    {
        if(values[golomb_config[i+1] - golomb_config[i]])
        {
            cout << "(POSL Exception) not valid golom to subsum construction [1] (GolombTools::golomb2subsum)" << endl;
            cout << Tools::configurationToString(golomb_config) << endl;
            exit(0);
            //throw "(POSL Exception) not valid golom to subsum construction [1] (GolombTools::golomb2subsum)";
        }
        values[golomb_config[i+1] - golomb_config[i]] = true;
        subsum_config[i] = golomb_config[i+1] - golomb_config[i];
    }
    unsigned int k = golomb_order - 1;
    for(unsigned int i = 1; i < values.size(); i++)
        if(!values[i] && k >= subsum_config.size())
            throw "(POSL Exception) not valid golom to subsum construction [2] (GolombTools::golomb2subsum)";
        else if (!values[i]) subsum_config[k++] = i;
    return subsum_config;
}
