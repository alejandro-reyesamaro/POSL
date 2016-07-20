#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"

class GolfersCustomWeekSwapNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        GolfersCustomWeekSwapNeighborhood(int _config_size, int _players, int _groups, vector<int> _zero_based_weeks);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, vector<int> &_configuration);

    private:
        void normalize_weeks();
        void updateChanges(shared_ptr<Randomizer> rand);
        void save_changes(int g1, int g2, int week);

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int players, groups, weeks;
        std::vector<int> indexes;
        std::vector<T_Changes> changes;
        vector<int> weeks_2_swap;
};
