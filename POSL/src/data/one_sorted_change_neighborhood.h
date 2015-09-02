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
#include "t_change.h"
#include "dStrategy/elements_change_iterator.h"

#include <random>

/*!
 * \class OneSortedChangeNeighborhood one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 */
class OneSortedChangeNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:
        OneSortedChangeNeighborhood(Solution * sol);

        POSL_Iterator<vector<int>> * getIterator(){ return new ElementsChangeIterator(this); }
        int size() { return changes.size(); }
        vector<T_change> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);

        FactoryPacker * BuildPacker();

    private:
        vector<int> applyChangeAt(int index);

        vector<T_change> changes;
        //Randomizer rand;
};
