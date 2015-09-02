#pragma once

/**
 * POSL
 *
 * \file golfers_single_swap_neighborhood.h
 * \brief Class to represent a neighborhood, swaping elements, but not in the first part
 * \author Alejandro Reyes
 * \date 2015-07-07
 */

#include "neighborhood.h"
#include "solution.h"
#include "dStrategy/elements_change_iterator.h"

#include <random>

/*!
 * \class T_Nchanges certain_elements_changed_neighborhood.h
 * \brief Struct to a pair (positions, values) as a change in a configuration
 */
typedef struct
{
    //! Index of the first value
    int pos1;
    //! Index of the second value
    int pos2;
}T_SwapChanges;

/*!
 * \class GolfersSingleSwapNeighborhood golfers_single_swap_neighborhood.h
 * \brief Class to represent a neighborhood, swaping elements, but not in the first part
 */
class GolfersSingleSwapNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:
        GolfersSingleSwapNeighborhood(Solution * sol, int _players);

        POSL_Iterator<vector<int>> * getIterator() { return new ElementsChangeIterator(this); }
        int size() {return changes.size(); }
        vector<T_SwapChanges> GetChanges() { return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();


    private:
        vector<int> applyChangeAt(int index);
        vector<T_SwapChanges> changes;
        int players;
        vector<int> indexes;
};
