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
        UnionOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
