#pragma once

#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

class NIndex
{
    public:
        NIndex(int _value);
        int value;
        vector<NIndex *> nexts;
};

class RandIndexGenerator
{
    public:
        RandIndexGenerator(int _max, int _dim);
        vector<vector<int> > generate(int c);
        //vector<int> generate(int c);
        vector<NIndex *> indexes;

    private:
        int max;
        int dim;
        default_random_engine generator;


        NIndex * create_index(int initial_value, int max_value, int dim);
        void create_index2(vector<NIndex *> & indexes, int initial_value, int max_value, int dim);
        void chose(vector<NIndex *> &_allind, vector<int> &ind, int dim);
};
