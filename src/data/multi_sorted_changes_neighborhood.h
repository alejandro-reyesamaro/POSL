#pragma once

/**
 * POSL
 *
 * \file multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 * \author Alejandro Reyes
 * \date 2015-08-10
 */

#include "../solver/psp.h"
#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "../tools/t_changes.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class MultiSortedChangesNeighborhood multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 */
class MultiSortedChangesNeighborhood : public Neighborhood, public DynamicNeighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        MultiSortedChangesNeighborhood(std::shared_ptr<Domain> _domain, int _config_size);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size(){ return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, std::vector<int> & _configuration);

    private:
        void pushSetOfValues(shared_ptr<Randomizer> rand, std::vector<int> indexes);
        void updateChanges(shared_ptr<Randomizer> rand);

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::shared_ptr<Domain> domain;
        std::vector<T_Changes> changes;        
};
