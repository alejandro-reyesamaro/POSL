#pragma once
#include "neighborhood.h"

class UnionNeighborhood : public Neighborhood
{
    friend class UnionIterator;
    public:
        //! Constructor (to build the structures)
        UnionNeighborhood(Neighborhood * v1, Neighborhood * v2);

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

    private:
        Neighborhood * V1, * V2;
};
