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
#include "dynamic_neighborhood.h"
#include "t_changes.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class GolfersSingleSwapNeighborhood golfers_single_swap_neighborhood.h
 * \brief Class to represent a neighborhood, swaping elements, but not in the first part
 */
class GolfersSingleSwapNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        GolfersSingleSwapNeighborhood(int _config_size, int _players, int _groups);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;        
        int players, groups;

        std::vector<int> indexes;
        //std::vector<int> indexes_IG;
        //std::vector<int> indexes_IP;

        std::vector<T_Changes> changes;
};
