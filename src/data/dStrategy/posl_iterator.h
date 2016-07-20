#pragma once

/**
 * POSL
 *
 * \file posl_iterator.h
 * \brief Interface to represent iterators
 * \author Alejandro Reyes
 * \date 2015-04-15
 */
#include <vector>

/*!
 * \class POSL_Iterator posl_iterator.h
 * \brief Interface to represent iterators
 */
//template <typename T>
class POSL_Iterator
{
    public:
        virtual std::vector<int> GetNext() = 0;
        virtual bool SomeNext() = 0;
        virtual void Reset() = 0;
};
