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
        RandIndexGenerator(int configuration_size);
        vector<vector<int> > generate(int card_changes);
        vector<vector<int> > generate();


    private:
        int dim;
        Matrix indexes;        
};
