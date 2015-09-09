#pragma once

/**
 * POSL
 *
 * \file node.h
 * \brief Template-class to represent a node (linked lists)
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

#include <memory>

/*!
 * \class Node node.h
 * \brief Template-class to represent a node (linked lists)
 */
template <class T>
class Node
{
    public:
        //! Constructor
        /*!
        * \param _value The node value
        * \param _next A pointer to the next node in the linked list
        */
        Node(T _value, std::shared_ptr<Node<T>> _next):value(_value), next(_next){}

        //! Constructor (next node dull)
        /*!
        * \param _value The node value
        */
        Node(T _value):value(_value){}

        //! The value
        T value;

        //! A pointer to the next value
        std::shared_ptr<Node<T>> next;
};
