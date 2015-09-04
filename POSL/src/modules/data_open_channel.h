#pragma once

/**
 * POSL
 *
 * \file data_open_channel.h
 * \brief Class to represent an Open Channel receiving data
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "open_channel.h"

/*!
 * \class DataOpenChannel data_open_channel.h
 * \brief Class to represent an Open Channel receiving data
 */
class DataOpenChannel : public OpenChannel
{
    public:
        //! Constructor
        DataOpenChannel(Benchmark * _bench);
        ComputationData * execute(PSP * psp, ComputationData * input);
        string codeToSend();
        virtual int dataTag() = 0;
        virtual ComputationData * unpackMessage(int * buffer, PSP * psp) = 0;

    protected:
        Benchmark * bench;
};
