#pragma once

/**
 * POSL
 *
 * \file neighborhood.h
 * \brief (Abstract) Class to represent a neighborhood of a configuration
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "dStrategy/posl_iterator.h"
#include "computation_data.h"
#include <vector>

using namespace std;

/*!
 * \class Neighborhood neighborhood.h
 * \brief (Abstract) Class to represent a neighborhood of a configuration
 */
class Neighborhood : public ComputationData
{
    public:
        //! Constructor
        Neighborhood();

        //! Returns an iterator (POSL_Iterator) to the values
        /*!
        * \return The iterator to the values
        */
        virtual POSL_Iterator<vector<int>> * getIterator() = 0;

        //! Returns the numbers of values in the Neighborhood
        /*!
        * \return Number of values in the Neighborhood
        */
        virtual int size() = 0;

        //! Returns the i-th value (configuration) in the set
        /*!
        * \param index Index of the required value
        * \return The value (configuration) in the position index
        */
        virtual vector<int> operator[](int index) = 0;
};

