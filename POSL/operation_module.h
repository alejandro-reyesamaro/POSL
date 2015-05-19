#pragma once

/**
 * POSL
 *
 * \file operation_module.h
 * \brief Class to represent an Open Channel
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

/*!
 * \class OperationModule operation_module.h
 * \brief Class to represent an Open Channel
 */


template <typename IN, typename OUT>
class OperationModule
{
    public:
        //! Constructor
        //OperationModule();
        virtual OUT execute(IN input) = 0;
};
