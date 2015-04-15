#pragma once

/**
 * POSL
 *
 * \file posl_iterator.h
 * \brief Interface to represent iterators
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

/*!
 * \class POSL_Iterator posl_iterator.h
 * \brief Interface to represent iterators
 */
class POSL_Iterator
{
    public:
        //! Returns the next value
        /*!
        * \return The next Value to be returned
        */
        virtual int GetNext() = 0;

        //! Returns true if there are more values to iterate with
        /*!
        * \return True if there are more values to iterate with
        */
        virtual bool SomeNext() = 0;

        //! Reset the iterator (all the values can be returned again)
        virtual void Reset() = 0;
};
