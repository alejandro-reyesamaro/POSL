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
#include "t_changes.h"
#include "dStrategy/elements_change_iterator.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

/*!
 * \class OnePermutationNeighborhood one_permutation_neighborhood.h
 * \brief Class to represent a neighborhood, performing a single permutation
 */
class OnePermutationNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        OnePermutationNeighborhood(int _config_size);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator(){ return make_shared<ElementsChangeIterator>(this); }
        int size(){ return changes.size(); }
        vector<T_Changes> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();
        void Init(vector<int> _configuration);

    private:
        void updateChanges();

        shared_ptr<ApplyChangeBehavior> changeAtBhv;
        vector<T_Changes> changes;
        vector<int> monotony;
};
