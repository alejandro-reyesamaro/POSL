#pragma once

/**
 * FoolSolver
 *
 * \file factory_domain.h
 * \brief Interface for factory domain
 * \author Alejandro Reyes
 * \date 2014-08-20
 */

#include <vector>

/*!
 * \class Factory_Domain factory_domain.h
 * \brief Interface for factory domain
 */
class FactoryDomain
{
    public:
        virtual std::vector<int> BuildDomain() = 0;
};
