#pragma once

#include "matrix.h"

#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

class RandIndexGenerator
{
    public:
        RandIndexGenerator(int configuration_size, int _dim);
        vector<vector<int> > generate();


    private:
        Matrix indexes;
        int dim;
        default_random_engine generator;

        /*
        NIndex * create_index(int initial_value, int max_value, int dim);
        void create_index(vector<NIndex *> & indexes, int initial_value, int max_value, int dim);
        void chose(vector<NIndex *> &_allind, vector<int> &ind, int dim);
        */
};
