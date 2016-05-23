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
        virtual std::vector<int> GetValues(int variable) = 0;
        virtual int minimum(int variable) = 0;
        virtual int maximum(int variable) = 0;
};
