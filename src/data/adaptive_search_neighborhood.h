#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"
#include "../benchmarks/benchmark.h"

class AdaptiveSearchNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        AdaptiveSearchNeighborhood(std::shared_ptr<Benchmark> _benchmark);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, vector<int> & _configuration);

    private:
        void updateChanges(std::shared_ptr<Randomizer> rand);

        std::shared_ptr<Benchmark> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<int> monotony;
        std::vector<T_Changes> changes;
};
