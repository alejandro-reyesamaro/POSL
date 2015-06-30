#include "rand_index_generator.h"

#include <iostream>
#include <math.h>
#include <algorithm>

RandIndexGenerator::RandIndexGenerator(int configuration_size, int _dim)
    :dim((int)sqrt(configuration_size)), generator(chrono::system_clock::now().time_since_epoch().count()), indexes((int)sqrt(configuration_size))
{
    //NO SE ESTA TOMANDO EN CUENTA  dim

    int n = (int)sqrt(configuration_size);
    vector<int> conf_index;
    for (int i = 0; i < configuration_size; i++)
        conf_index.push_back(i);

    random_shuffle (conf_index.begin(), conf_index.end());

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            indexes.setValue(i, j, conf_index[i * n + j]);
}

vector<vector<int>> RandIndexGenerator::generate()
{
    int max_to_generate = dim * 4;

    vector<vector<int>> sets_of_index;

    // rows
    for(int i = 0; i < dim; i++)
    {
        vector<int> ind;
        chose(indexes, ind, dim);
        sets_of_index.push_back(ind);
    }
    //cout << "retorna" << endl;
    return sets_of_index;
}
