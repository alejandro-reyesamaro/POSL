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
#include "t_nchanges.h"

#include <random>

/*!
 * \class MultiSortedChangesNeighborhood multi_sorted_changes_neighborhood.h
 * \brief Class to represent a neighborhood, changing some values randomly at the time (sorted)
 */
class MultiSortedChangesNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:

        //! Constructor (to build the structures)
        MultiSortedChangesNeighborhood(Solution * sol);

        //! Returns the iterator over the elements of the set
        /*!
        * \return Interator over the set of configurations
        */
        POSL_Iterator<vector<int>> * getIterator();

        //! Returns the nomber of elements in the neighborhood
        /*!
        * \return Nomber of elements in the neighborhood
        */
        int size();

        //! Returns the element (configuration) at the position index
        /*!
        * \param index Position of the required element (configuration)
        * \return The element (configuration) at the position index
        */
        vector<int> operator[](int index);

        //! From Packable
        vector<int> pack();
        int bodySize();
        vector<int> body();

    private:
        //! Returns a new configuration: the value at the position changes[index].pos is changed by changes[index].new_value
        /*!
        * \param index Index of the configuration inthe (virtual) neighborhood
        * \return The configuration with the changes applied
        */
        vector<int> applyChangeAt(int index);

        //! The current configuration (we are computing the neighborhood of it)
        Solution * current_solution;

        //! Vector of changes
        vector<T_Nchanges> changes;

        //! Random generator
        Randomizer rand;
};
