#pragma once

/**
 * POSL
 *
 * \file multi_elements_changed_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time
 * \author Alejandro Reyes
 * \date 2015-05-30
 */

#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "t_changes.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class MultiElementsChangedNeighborhood multi_elements_changed_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time
 */
class MultiElementsChangedNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        MultiElementsChangedNeighborhood(int _config_size, std::vector<Domain> _domainsl);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<Domain> domains;
        Randomizer rand;
        std::vector<T_Changes> changes;        
};
