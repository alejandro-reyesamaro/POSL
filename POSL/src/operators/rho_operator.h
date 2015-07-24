#pragma once

/**
 * POSL
 *
 * \file rho_operator.h
 * \brief Class to represent the RHO binary operator
 * \author Alejandro Reyes
 * \date 2015-06-23
 */

#include "binary_operator.h"

/*!
 * \class RhoOperator rho_operator.h
 * \brief Class to represent the RHO operator
 */
class RhoOperator : public BinaryOperator
{
    public:
        //! Contructor
        /*!
         * \param _M1 Module
         * \param _M2 Module
         * \param _rho Probability
         */
        RhoOperator(CompoundModule * _M1, CompoundModule * _M2, float _rho);

        //! From Codable
        string codeToSend();

    private:
        float rho;
};
