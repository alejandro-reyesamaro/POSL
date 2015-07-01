#include "rand_index_generator.h"

#include <iostream>
#include <math.h>
#include <algorithm>

RandIndexGenerator::RandIndexGenerator(int configuration_size, int _dim)
    :dim((int)sqrt(configuration_size)), indexes((int)sqrt(configuration_size))
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
    vector<vector<int>> sets_of_index;

    for(int i = 0; i < dim; i++)
    {
        vector<int> ind = indexes.row(i);
        sets_of_index.push_back(ind);

        ind = indexes.column(i);
        sets_of_index.push_back(ind);

        ind = indexes.diagonalRigth(i);
        sets_of_index.push_back(ind);

        ind = indexes.diagonalLeft(i);
        sets_of_index.push_back(ind);
    }
    return sets_of_index;
}
