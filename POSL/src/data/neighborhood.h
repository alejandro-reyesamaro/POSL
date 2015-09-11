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
#define NEIGHBORHOOD_PACKING_ID 658203

/*!
 * \class Neighborhood neighborhood.h
 * \brief (Abstract) Class to represent a neighborhood of a configuration
 */
class Neighborhood : public ComputationData
{
    public:
        Neighborhood(std::vector<int> _current_configuration);
        Neighborhood(int _config_size);

        virtual std::shared_ptr<POSL_Iterator> getIterator() = 0;
        virtual int size() = 0;
        virtual std::vector<int> neighborAt(int index) = 0;

        std::vector<int> CurrentConfiguration(){ return current_configuration; }

    protected:        
        std::vector<int> current_configuration;
};

