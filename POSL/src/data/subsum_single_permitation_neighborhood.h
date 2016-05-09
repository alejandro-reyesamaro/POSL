#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"

class SubsumSinglePermitationNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        SubsumSinglePermitationNeighborhood(int _set_length, int _subsum_length);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, vector<int> & _configuration);

    private:
        void updateChanges(shared_ptr<Randomizer> rand);

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int set_length;
        int subsum_length;
        std::vector<int> subsum_valid_index;
        std::vector<int> not_valid_index;
        std::vector<T_Changes> changes;
};
