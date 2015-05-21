#pragma once

/**
 * POSL
 *
 * \file compound_module.h
 * \brief Class to represent a Compound Module
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

/*!
 * \class CompoundModule compound_module.h
 * \brief Class to represent a Compound Module
 */
template <typename IN, typename OUT>
class CompoundModule
{
    public:
        //! Constructor
        CompoundModule();
        virtual OUT execute(IN input) = 0;
};
