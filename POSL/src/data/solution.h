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
#define TAGSOLUTION "cd_S"

/*!
 * \class Solution solution.h
 * \brief Class to represent a solution (configuration)
 */
class Solution : public ComputationData, public std::enable_shared_from_this<Solution>
{
    public:
        Solution(std::shared_ptr<Domain> _domains, int dimension);
        Solution(std::shared_ptr<Domain> _domains, std::vector<int> conf);

        void UpdateConfiguration(std::vector<int> new_config);
        void UpdateConfigurationFromPack(int * pack);
        bool equal(std::shared_ptr<Solution> other);
        std::string configurationToString();
        std::shared_ptr<FactoryPacker> BuildPacker();

        std::vector<int> get_conf_by_copy() { return configuration; }
        std::vector<int> & get_conf_by_ref() { return configuration; }

        std::shared_ptr<Domain> GetVariablesDomain(){ return variables_domains; }

        std::string Tag() { return TAGSOLUTION; }

    private:
        std::shared_ptr<Domain> variables_domains;
        std::vector<int> configuration;
};
