#pragma once
#include "neighborhood.h"
#include "solution.h"

class UnionNeighborhood : public Neighborhood
{
    friend class UnionIterator;
    public:
        UnionNeighborhood(shared_ptr<Solution> sol, shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator(){ return make_shared<UnionIterator>(this); }
        // OPTIMIZAR : calcular bien la cantidad
        int size(){ return V1->size() + V2->size(); }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();

    private:
        Neighborhood * V1, * V2;
};
