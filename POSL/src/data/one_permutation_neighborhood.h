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
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class OnePermutationNeighborhood one_permutation_neighborhood.h
 * \brief Class to represent a neighborhood, performing a single permutation
 */
class OnePermutationNeighborhood : public Neighborhood, public DynamicNeighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        OnePermutationNeighborhood(int _config_size);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size(){ return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;        
        std::vector<int> monotony;
        std::vector<T_Changes> changes;
};
