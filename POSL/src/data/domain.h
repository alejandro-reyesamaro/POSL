#pragma once

/**
 * POSL
 *
 * \file domain.h
 * \brief Class to represent the domain of a variable
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include <vector>

/*!
 * \class Domain domain.h
 * \brief Class to represent the domain of a variable
 */
class Domain
{
    public:
        Domain(int _min_value, int _max_value);

        std::vector<int> GetValues();
        int minimum();
        int maximum();

    private:
        int min_value;
        int max_value;
};
