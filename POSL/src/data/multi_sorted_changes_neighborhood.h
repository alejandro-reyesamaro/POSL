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
#include "t_changes.h"
#include "dStrategy/elements_change_iterator.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

/*!
 * \class MultiSortedChangesNeighborhood multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 */
class MultiSortedChangesNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        MultiSortedChangesNeighborhood(int _config_size, vector<Domain> _domains);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator(){ make_shared<ElementsChangeIterator>(this); }
        int size(){ return changes.size(); }
        vector<T_Changes> GetChanges(){ return changes; }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();
        void Init(vector<int> _configuration);

    private:
        void pushSetOfValues(vector<int> indexes);
        void updateChanges();

        shared_ptr<ApplyChangeBehavior> changeAtBhv;
        vector<Domain> domains;
        vector<T_Changes> changes;
        Randomizer rand;
};
