#pragma once

/**
 * POSL
 *
 * \file open_channel.h
 * \brief Class to represent an Open Channel
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "compound_module.h"

#define TAGOCh "OCh"
/*!
 * \class OpenChannel open_channel.h
 * \brief Class to represent an Open Channel
 */
class OpenChannel : public CompoundModule
{
    public:
        virtual std::string Tag(){ return TAGOCh; }
};

