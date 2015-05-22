#pragma once

#include "posl_iterator.h"
#include "computation_data.h"
#include <vector>

using namespace std;

class Neighborhood : public ComputationData
{
    public:
        Neighborhood();

        virtual POSL_Iterator<vector<int>> * getIterator() = 0;
        virtual int size() = 0;
        virtual vector<int> operator[](int index) = 0;
};

