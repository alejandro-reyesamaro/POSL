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

#include <vector>
#include <string>

using namespace std;

#define SOLUTION_PACKING_ID 658201

/*!
 * \class Solution solution.h
 * \brief Class to represent a solution (configuration)
 */
class Solution : public ComputationData//, public Packable
{
    public:
        Solution(vector<Domain> _domains);
        Solution(vector<Domain> _domains, vector<int> conf);

        void UpdateConfiguration(vector<int> new_config);
        bool equal(Solution * other);
        string configurationToString();
        FactoryPacker * BuildPacker();

        vector<int> GetConfiguration(){ return configuration; }
        vector<Domain> GetDomains(){ return domains; }

    private:
        vector<Domain> domains;
        vector<int> configuration;
};
