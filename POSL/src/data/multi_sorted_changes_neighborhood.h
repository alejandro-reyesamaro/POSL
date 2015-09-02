#pragma once

/**
 * POSL
 *
 * \file multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 * \author Alejandro Reyes
 * \date 2015-08-10
 */

#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "t_nchanges.h"
#include "dStrategy/elements_change_iterator.h"

#include <random>

/*!
 * \class MultiSortedChangesNeighborhood multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 */
class MultiSortedChangesNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:
        MultiSortedChangesNeighborhood(Solution * sol);

        POSL_Iterator<vector<int>> * getIterator(){ new ElementsChangeIterator(this); }
        int size(){ return changes.size(); }
        vector<T_Nchanges> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();

    private:
        vector<int> applyChangeAt(int index);
        void pushSetOfValues(vector<int> indexes, Solution * sol);

        vector<T_Nchanges> changes;
        Randomizer rand;
};
