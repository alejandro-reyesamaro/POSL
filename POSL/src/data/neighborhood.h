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

using namespace std;

#define NEIGHBORHOOD_PACKING_ID 658203

/*!
 * \class Neighborhood neighborhood.h
 * \brief (Abstract) Class to represent a neighborhood of a configuration
 */
class Neighborhood : public ComputationData
{
    public:
        Neighborhood(vector<int> _current_configuration);

        virtual POSL_Iterator<vector<int>> * getIterator() = 0;
        virtual int size() = 0;
        virtual vector<int> neighborAt(int index) = 0;

    protected:        
        vector<int> current_configuration;
        vector<int> configuration_changed;
};

