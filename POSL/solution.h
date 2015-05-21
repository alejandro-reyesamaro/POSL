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
#include <memory>

using namespace std;

/*!
 * \class Solution solution.h
 * \brief Class to represent a solution (configuration)
 */
class Solution : ComputationData
{
    public:
        //! Constructor
        /*!
        * \param _domains The variables domais
        */
        Solution(vector<Domain> _domains);
        Solution(vector<Domain> _domains, vector<int> conf);



    //private:
        //! The current configuration
        vector<int> configuration;

        //! The variables domains
        vector<Domain> domains;
};
