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
        DataOpenChannel(shared_ptr<Benchmark> _bench);
        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        string codeToSend();
        virtual int dataTag() = 0;
        virtual shared_ptr<ComputationData> unpackMessage(int * buffer, shared_ptr<PSP> psp) = 0;

    protected:
        shared_ptr<Benchmark> bench;
};
