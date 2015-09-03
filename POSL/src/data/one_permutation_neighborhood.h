#pragma once

/**
 * POSL
 *
 * \file one_permutation_neighborhood.h
 * \brief Class to represent a neighborhood, performing a single permutation
 * \author Alejandro Reyes
 * \date 2015-08-31
 */

#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "t_nchanges.h"
#include "dStrategy/elements_change_iterator.h"
#include "dynamic_neighborhood.h"

#include <random>

/*!
 * \class OnePermutationNeighborhood one_permutation_neighborhood.h
 * \brief Class to represent a neighborhood, performing a single permutation
 */
class OnePermutationNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        OnePermutationNeighborhood(Solution * sol);

        POSL_Iterator<vector<int>> * getIterator(){ return new ElementsChangeIterator(this); }
        int size(){ return changes.size(); }
        vector<T_Nchanges> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        FactoryPacker * BuildPacker();
        void update(vector<int> _configuration);

    private:
        vector<int> applyChangeAt(int index);
        void updateChanges();

        vector<T_Nchanges> changes;
        Randomizer rand;
        vector<int> monotony;
};
