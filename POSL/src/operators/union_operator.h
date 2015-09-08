/**
 * POSL
 *
 * \file union_operator.h
 * \brief Class to represent the UNION operator
 * \author Alejandro Reyes
 * \date 2015-07-01
 */

#include "binary_operator.h"

/*!
 * \class UnionOperator union_operator.h
 * \brief Class to represent the UNION operator
 */
class UnionOperator : public BinaryOperator
{
    public:
        UnionOperator(shared_ptr<CompoundModule> _M1, shared_ptr<CompoundModule> _M2);

        //! From Codable
        string codeToSend();
};
