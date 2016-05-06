#pragma once

#include "../solver/psp.h"
#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "../tools/t_changes.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

class OneWorstSortedChangeNeighborhood : public Neighborhood, public DynamicNeighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        OneWorstSortedChangeNeighborhood(int _config_size, shared_ptr<Benchmark> _benchmark);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, std::vector<int> & _configuration);

    private:
        void updateChanges(shared_ptr<Randomizer> rand);

        std::shared_ptr<Benchmark> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<T_Changes> changes;
};
