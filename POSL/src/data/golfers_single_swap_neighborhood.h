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
#include "dynamic_neighborhood.h"
#include "t_changes.h"
#include "dStrategy/apply_change_behavior.h"

#include <random>

/*!
 * \class GolfersSingleSwapNeighborhood golfers_single_swap_neighborhood.h
 * \brief Class to represent a neighborhood, swaping elements, but not in the first part
 */
class GolfersSingleSwapNeighborhood : public Neighborhood, public DynamicNeighborhood
{
    friend class ElementsChangeIterator;
    public:
        GolfersSingleSwapNeighborhood(int _config_size, int _players);

        shared_ptr<POSL_Iterator<vector<int>>> getIterator() { return make_shared<ElementsChangeIterator>(this); }
        int size() {return changes.size(); }
        vector<T_Changes> GetChanges() { return changes; }

        vector<int> neighborAt(int index);
        shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        shared_ptr<ApplyChangeBehavior> changeAtBhv;
        vector<T_Changes> changes;
        int players;
        vector<int> indexes;
};
