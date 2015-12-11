#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"
#include "../tools/randomizer.h"
#include "../benchmarks/benchmark.h"
#include "../tools/fixed_size_vector.h"

class AdaptiveSearchNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        AdaptiveSearchNeighborhood(std::shared_ptr<Benchmark> _benchmark, int _config_size);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<Benchmark> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        Randomizer rand;
        std::vector<int> monotony;
        std::vector<T_Changes> changes;
        FixedSizeVector<int> bad_variables;
};
