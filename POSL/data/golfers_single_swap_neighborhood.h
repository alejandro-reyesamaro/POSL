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

#include <random>

/*!
 * \class T_Nchanges certain_elements_changed_neighborhood.h
 * \brief Struct to a pair (positions, values) as a change in a configuration
 */
typedef struct
{
    //! Index of the first value
    int pos1;
    //! Index of the second value
    int pos2;
}T_SwapChanges;

/*!
 * \class GolfersSingleSwapNeighborhood golfers_single_swap_neighborhood.h
 * \brief Class to represent a neighborhood, swaping elements, but not in the first part
 */
class GolfersSingleSwapNeighborhood : public Neighborhood
{
    friend class ElementsChangeIterator;
    public:

        //! Constructor (to build the structures)
        /*!
        * \param sol The solution (configuration)
        * \param _players The number of players (golfers)
        */
        GolfersSingleSwapNeighborhood(Solution * sol, int _players);

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
        int * pack();
        int bodySize();
        int * body();

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
        vector<T_SwapChanges> changes;

        //! The number of players
        int players;
};
