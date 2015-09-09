/**
 * POSL
 *
 * \file one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "neighborhood.h"
#include "solution.h"
#include "../tools/randomizer.h"
#include "t_changes.h"
#include "dynamic_neighborhood.h"
#include "dStrategy/apply_change_behavior.h"

//#include <random>

/*!
 * \class OneSortedChangeNeighborhood one_sorted_change_neighborhood.h
 * \brief Class to represent a neighborhood, changing one value randomly at the time (sorted)
 */
class OneSortedChangeNeighborhood : public Neighborhood, public DynamicNeighborhood, public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        OneSortedChangeNeighborhood(int _config_size);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges(){ return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(std::vector<int> _configuration);

    private:
        void updateChanges();

        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<T_Changes> changes;
};
