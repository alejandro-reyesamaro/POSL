#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"
#include "../benchmarks/golfers.h"

class GolfersAdaptiveSearchNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        GolfersAdaptiveSearchNeighborhood(std::shared_ptr<Golfers> _bench, int _config_size, int _players, int _groups);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);
        void SetSeed(std::shared_ptr<Seed> _seed);

    private:
        void updateChanges();
        void save_swap(int pos1, int pos2);

        std::shared_ptr<Golfers> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int players, groups, weeks;        
        std::vector<int> w_index;
        std::vector<T_Changes> changes;
        std::shared_ptr<Seed> my_seed;
};
