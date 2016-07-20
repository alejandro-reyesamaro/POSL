#pragma once

/**
 * POSL
 *
 * \file computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "../packing/factory/factory_packer.h"

#include <vector>
#include <memory>
#include <string>
#include <functional>

/*!
 * \class ComputationData computation_data.h
 * \brief (Abstract) Class to represent all types of I/O in POSL
 */
class ComputationData
{
    public:
        virtual std::shared_ptr<FactoryPacker> BuildPacker() = 0;
        virtual std::string Tag() = 0;

        //! Compare this object with other, given a function (criteria)
        /*!
            \param other The ComputationData to compare with.
            \param criteria A function (criteria).
            \return -1 if THIS is lower, 1 if THIS is bigger, 0 if equals
         */
        virtual int comapareTo(std::shared_ptr<ComputationData> other,
                               std::function<int(std::shared_ptr<ComputationData>)> criteria) = 0;
};
