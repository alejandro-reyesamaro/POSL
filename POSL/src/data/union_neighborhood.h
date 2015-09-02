#pragma once
#include "neighborhood.h"
#include "solution.h"

class UnionNeighborhood : public Neighborhood
{
    friend class UnionIterator;
    public:
        UnionNeighborhood(Solution * sol, Neighborhood * v1, Neighborhood * v2);

        POSL_Iterator<vector<int>> * getIterator();
        // OPTIMIZAR : calcular bien la cantidad
        int size(){ return V1->size() + V2->size(); }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();

    private:
        Neighborhood * V1, * V2;
};
