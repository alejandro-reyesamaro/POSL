/**
 * POSL
 *
 * \file one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "t_changes.h"
#include "dStrategy/elements_change_iterator.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

/*!
 * \class OneSortedChangeNeighborhood one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 */
class OneSortedChangeNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        OneSortedChangeNeighborhood(int _config_size);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator(){ return make_shared<ElementsChangeIterator>(this); }
        int size() { return changes.size(); }
        vector<T_Changes> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();
        void Init(vector<int> _configuration);

    private:
        void updateChanges();

        shared_ptr<ApplyChangeBehavior> changeAtBhv;
        vector<T_Changes> changes;
};
