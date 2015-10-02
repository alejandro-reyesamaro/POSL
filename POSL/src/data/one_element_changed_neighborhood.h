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
#include "../tools/t_changes.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class OneElementChangedNeighborhood one_element_changed_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value rndomly at the time
 */
class OneElementChangedNeighborhood : public Neighborhood, public DynamicNeighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        OneElementChangedNeighborhood(int _config_size, std::vector<Domain> _domains);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size(){ return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<Domain> domains;        
        Randomizer rand;
        std::vector<int> indexes;
        std::vector<T_Changes> changes;
};
