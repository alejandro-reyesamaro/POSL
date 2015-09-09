#pragma once
#include "neighborhood.h"
#include "solution.h"

class UnionNeighborhood : public Neighborhood, public std::enable_shared_from_this<UnionNeighborhood>
{
    friend class UnionIterator;
    public:
        UnionNeighborhood(std::shared_ptr<Solution> sol, std::shared_ptr<Neighborhood> v1, std::shared_ptr<Neighborhood> v2);

        std::shared_ptr<POSL_Iterator> getIterator();
        // OPTIMIZAR : calcular bien la cantidad
        int size(){ return V1->size() + V2->size(); }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();

    private:
        std::shared_ptr<Neighborhood> V1;
        std::shared_ptr<Neighborhood> V2;
};
