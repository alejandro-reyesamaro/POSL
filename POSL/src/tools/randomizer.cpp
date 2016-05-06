#include "randomizer.h"
#include "tools.h"
#include <chrono>       // std::chrono::system_clock
#include <algorithm>    // std::shuffle

using namespace std;
/*
unsigned generate_seed(int pID)
{
    return (pID >= 0) ?
        std::chrono::system_clock::now().time_since_epoch().count() * (pID + 1) :
        std::chrono::system_clock::now().time_since_epoch().count();
}
*/
Randomizer::Randomizer(int configuration_size)
    : r_generator(),//(generate_seed(pID)),
      dim((int)sqrt(configuration_size)),
      indexes((int)sqrt(configuration_size))
{
    vector<int> conf_index = Tools::generateMonotony(configuration_size);

    vector_shuffle(conf_index);

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            indexes.setValue(i, j, conf_index[i * dim + j]);
}

bool Randomizer::bernoulli(float p)
{
    p = min(p, 1.0f);
    p = max(0.0f, p);
    int k = NextInt(0, 100);
    return k < (int)(p*100);
}

int Randomizer::NextInt(int min, int max)
{
    return r_generator.next_int(min, max);
    //std::uniform_int_distribution<int> distribution(min, max);
    //return distribution(generator);
}

void Randomizer::vector_shuffle(vector<int> & vec)
{
    std::shuffle(vec.begin(), vec.end(), r_generator.GetGenerator());
}

void Randomizer::vector_shuffle(vector<int> & vec, int _begin, int _end)
{
    std::shuffle(vec.begin() + _begin, vec.begin() + _end, r_generator.GetGenerator());
}

vector<vector<int>> Randomizer::generate_multichanges(int card_changes)
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

vector<vector<int>> Randomizer::generate_multichanges()
{
    return generate_multichanges(4 * dim);
}
