#pragma once
/**
 * POSL
 *
 * \file speed_operator.h
 * \brief Class to represent the SPEED operator
 * \author Alejandro Reyes
 * \date 2015-07-21
 */

#include "binary_operator.h"

/*!
 * \class SpeedOperator speed_operator.h
 * \brief Class to represent the FasterOperator operator
 */
class SpeedOperator : public BinaryOperator
{
    public:
        SpeedOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
