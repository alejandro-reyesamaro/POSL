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
        //! Contructor
        /*!
         * \param _M1 Module
         * \param _M2 Module
         */
        SpeedOperator(CompoundModule * _M1, CompoundModule * _M2);
};
