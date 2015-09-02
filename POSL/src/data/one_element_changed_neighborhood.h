#pragma once

/**
 * POSL
 *
 * \file one_element_changed_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value rndomly at the time
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
 * \class OneElementChangedNeighborhood one_element_changed_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value rndomly at the time
 */
class OneElementChangedNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:
        OneElementChangedNeighborhood(Solution * sol);

        POSL_Iterator<vector<int>> * getIterator(){ return new ElementsChangeIterator(this); }
        int size(){ return changes.size(); }
        vector<T_change> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();

    private:
        vector<int> applyChangeAt(int index);

        vector<T_change> changes;
        Randomizer rand;
        vector<int> indexes;
};
