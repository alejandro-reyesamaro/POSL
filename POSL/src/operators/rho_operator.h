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
        RhoOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2, float _rho);

        //! From Codable
        string codeToSend();

    private:
        float rho;
};
