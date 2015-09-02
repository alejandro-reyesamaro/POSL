#pragma once

/**
 * POSL
 *
 * \file benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 * \author Alejandro Reyes
 * \date 2015-05-11
 */

#include "../data/solution.h"

#include <vector>

using namespace std;

/*!
 * \class Benchmark benchmark.h
 * \brief (Abstract) Class to represent an instance of a problem
 */
class Benchmark
{
    public:
        //! Constructor
        Benchmark(vector<Domain> _domains);

        //! The cost of a given Solution
        /*!
        * \param sol Solution
        * \return The cost of the Solution sol
        */
        int solutionCost(Solution * sol);
        virtual int solutionCost(vector<int> configuration) = 0;

        //! Updates the problem configuration (Solution)
        /*!
        * \param sol New solution to the problem
        */
        void UpdateSolution(Solution * sol);

        //! Returns the current configuration (Solution)
        /*!
        * \return Returns the current solution
        */
        Solution * GetSolution();

        //! Returns the Domain corresponding with the instance
        /*!
        * \return Domains list
        */
        vector<Domain> Domains();

        //! Shows the solution in its way
        /*!
        * \param solution The solution
        * \return The solution as a string
        */
        virtual string ShowSolution(Solution * solution) = 0;

    protected:
        //! Current solution of the problem
        Solution * solution;
        vector<Domain> domains;
};
