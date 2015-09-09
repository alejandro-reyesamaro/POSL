#pragma once

/**
 * POSL
 *
 * \file solution.h
 * \brief Class to represent a solution (configuration)
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

#include "domain.h"
#include "computation_data.h"

#include <string>

#define SOLUTION_PACKING_ID 658201

/*!
 * \class Solution solution.h
 * \brief Class to represent a solution (configuration)
 */
class Solution : public ComputationData, public std::enable_shared_from_this<Solution>
{
    public:
        Solution(std::vector<Domain> _domains);
        Solution(std::vector<Domain> _domains, std::vector<int> conf);

        void UpdateConfiguration(std::vector<int> new_config);
        void UpdateConfigurationFromPack(int * pack);
        bool equal(std::shared_ptr<Solution> other);
        std::string configurationToString();
        std::shared_ptr<FactoryPacker> BuildPacker();

        std::vector<int> GetConfiguration(){ return configuration; }
        std::vector<Domain> GetDomains(){ return domains; }

    private:
        std::vector<Domain> domains;
        std::vector<int> configuration;
};
