#pragma once

#include "posl_iterator.h"
#include <vector>
#include <memory>

using namespace std;

class Neighborhood
{
    public:
        Neighborhood();

        virtual POSL_Iterator<vector<int>> * getIterator() = 0;
        virtual int size() = 0;
        virtual vector<int> operator[](int index) = 0;
};

