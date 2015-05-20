#pragma once

#include "neighborhood.h"
#include "solution.h"

typedef struct
{
    int pos;
    int new_value;
}T_change;

class OneElementChangedNeighborhood : public Neighborhood
{
    friend class OneElementChangedIterator;
    public:
        OneElementChangedNeighborhood(shared_ptr<Solution> sol);

        POSL_Iterator<vector<int>> * getIterator();
        int size();
        vector<int> operator[](int index);

    private:
        vector<int> applyChangeAt(int index);

        shared_ptr<Solution> current_solution;
        vector<T_change> changes;
};
