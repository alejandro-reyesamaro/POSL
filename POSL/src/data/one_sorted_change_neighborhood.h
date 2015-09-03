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

#include <random>

/*!
 * \class OneSortedChangeNeighborhood one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 */
class OneSortedChangeNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        OneSortedChangeNeighborhood(Solution * sol);

        POSL_Iterator<vector<int>> * getIterator(){ return new ElementsChangeIterator(this); }
        int size() { return changes.size(); }
        vector<T_Changes> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();
        void update(vector<int> _configuration);

    private:
        vector<int> applyChangeAt(int index);
        void updateChanges();

        vector<T_Changes> changes;
        //Randomizer rand;
};
