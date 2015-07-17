#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "tools/randomizer.h"
#include "t_nchanges.h"

#include <random>

class FromPackNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:

        FromPackNeighborhood(int pack_size, int * pack);

        POSL_Iterator<vector<int>> * getIterator();
        int size();
        vector<int> operator[](int index);

        //! From Packable
        vector<int> pack();
        int bodySize();
        vector<int> body();

    private:
        vector<int> applyChangeAt(int index);

        vector<int> configuration;

        //! Vector of changes
        vector<T_Nchanges> changes;
};
