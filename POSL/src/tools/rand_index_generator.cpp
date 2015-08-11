#include "rand_index_generator.h"

#include <iostream>
#include <math.h>
#include <algorithm>

RandIndexGenerator::RandIndexGenerator(int configuration_size, int _dim)
    : dim(min((int)sqrt(configuration_size),_dim)), indexes(min((int)sqrt(configuration_size),_dim))
{
    vector<int> conf_index;
    for (int i = 0; i < configuration_size; i++)
        conf_index.push_back(i);
    srand(time(0));
    random_shuffle (conf_index.begin(), conf_index.end());

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            indexes.setValue(i, j, conf_index[i * dim + j]);
}

RandIndexGenerator::RandIndexGenerator(int configuration_size)
    : RandIndexGenerator(configuration_size, (int)sqrt(configuration_size))
{}

vector<vector<int>> RandIndexGenerator::generate(int card_changes)
{
    card_changes = min (card_changes, 4 * dim);
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

    // mejorar esto :
    if(card_changes < sets_of_index.size())
    {
        vector<vector<int>> v(card_changes);
        copy ( sets_of_index.begin(), sets_of_index.begin() + card_changes, v.begin() );
        return v;
    }
    else
        return sets_of_index;
}

vector<vector<int>> RandIndexGenerator::generate()
{
    return generate(4 * dim);
}
