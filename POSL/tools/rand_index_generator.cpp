#include "rand_index_generator.h"

#include <iostream>


NIndex::NIndex(int _value) : value(_value){}

RandIndexGenerator::RandIndexGenerator(int _max, int _dim):max(_max), dim(_dim), generator(chrono::system_clock::now().time_since_epoch().count())
{
    create_index2(indexes, 0, max, dim);
}

/*
vector<int> RandIndexGenerator::generate(int c){
    vector<int> indexes;
    for (int i = 0; i <= max; i++)
        indexes.push_back(i);
    random_shuffle (indexes.begin(), indexes.end());
    vector<int> v (c);
    copy ( indexes.begin(), indexes.begin()+7, v.begin() );
    return v;
}
*/

NIndex * RandIndexGenerator::create_index(int initial_value, int max_value, int dim)
{
    if(dim != 1)
    {
        NIndex * index = new NIndex(initial_value);
        //cout << dim << "|" << dim << ": value = " << initial_value << endl;
        for(unsigned int i = initial_value + 1; i <= max_value; i++)
        {
            index->nexts.push_back(create_index(i, max_value, dim - 1));
        }
        return index;
    }
    else
    {
        //cout << " nivel " << dim << ": value = " << initial_value << endl;
        return new NIndex(initial_value);
    }
}


void RandIndexGenerator::create_index2(vector<NIndex *> & indexes, int initial_value, int max_value, int dim)
{
    for(int i = initial_value; i<= max_value; i++)
    {
        if(i + dim - 1 <= max_value)
        {
            NIndex * ni = new NIndex(i);
            indexes.push_back(ni);
            create_index2(ni->nexts, i+1, max_value, dim - 1);
        }
    }
}


void my_random_shuffle(vector<NIndex *> indexes)
{
    random_shuffle (indexes.begin(), indexes.end());
    for(unsigned int i = 0; i < indexes.size(); i++)
        my_random_shuffle(indexes[i]->nexts);
}

void RandIndexGenerator::chose(vector<NIndex *> & _allind, vector<int> & ind, int dim)
{
    cout << "entra en chosse" << endl;
    uniform_int_distribution<int> distribution(0, _allind.size()-1);
    int new_index = distribution(generator);
    cout << "new index: " << new_index << endl;
    if(dim == 1)
    {
        int v = _allind[new_index]->value;
        ind.push_back(v);
        _allind.erase(_allind.begin()+new_index);
    }
    else
    {
        chose(_allind[new_index]->nexts, ind, dim-1);
        ind.push_back(_allind[new_index]->value);
        if(_allind[new_index]->nexts.size() == 0)
            _allind.erase(_allind.begin()+new_index);
    }
}


//AUN
vector<vector<int>> RandIndexGenerator::generate(int c)
{
    vector<vector<int>> sets_of_index;

    for(int i = 0; i < c; i++)
    {
        vector<int> ind;
        chose(indexes, ind, dim);



        sets_of_index.push_back(ind);
    }
    //cout << "retorna" << endl;
    return sets_of_index;
}

