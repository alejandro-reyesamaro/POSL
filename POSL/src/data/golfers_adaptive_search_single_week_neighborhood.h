#pragma once

#include "neighborhood.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"
#include "../benchmarks/golfers.h"

class GolfersAdaptiveSearchSingleWeekNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        GolfersAdaptiveSearchSingleWeekNeighborhood(std::shared_ptr<Golfers> _bench, int _config_size, int _players, int _groups, int _zero_based_week_2_swap);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP>, std::vector<int> & _configuration);

    private:
        void updateChanges();
        void save_swap(int pos1, int pos2);
        int init_weeks(int _week);

        std::shared_ptr<Golfers> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int players, groups, weeks;
        int week_2_swap;
        std::vector<T_Changes> changes;
        std::shared_ptr<Seed> my_seed;
};
