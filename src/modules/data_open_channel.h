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
        DataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData>);

        virtual int dataID() = 0;        
        virtual void storeMessage(int * buffer, std::shared_ptr<PSP> psp) = 0;
        virtual std::shared_ptr<ComputationData> selectMessage() = 0;

    protected:
        void receive_and_log(int id, int tag, std::shared_ptr<PSP> psp);
        //bool ContainsInformation() { return contains_information; }

        bool contains_information;
        std::shared_ptr<Benchmark> bench;
        //std::shared_ptr<ComputationData> received_data;

    private:
        bool logging;
        bool logged;
        MPI_Status status;
        std::vector<int> buffer;        
};
