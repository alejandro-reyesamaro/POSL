#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"

class GolfersSingleWeekSwapNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        GolfersSingleWeekSwapNeighborhood(int _config_size, int _players, int _groups, int _zero_based_week);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        int init_weeks(int _week);
        void updateChanges();
        void save_changes(int g1, int g2, int week);

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int players, groups;
        std::vector<int> indexes;
        std::vector<T_Changes> changes;
        int week;
};
