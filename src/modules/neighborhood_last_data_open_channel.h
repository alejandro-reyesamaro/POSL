#pragma once

#include "data_open_channel.h"
#include "../data/from_pack_neighborhood.h"

class NeighborhoodLastDataOpenChannel : public DataOpenChannel
{
    public:
        NeighborhoodLastDataOpenChannel(std::string name, std::shared_ptr<Benchmark> _bench);
        int dataID();
        std::string codeToSend();

        void storeMessage(int * buffer, std::shared_ptr<PSP>);
        shared_ptr<ComputationData> selectMessage();

    private:
        std::shared_ptr<FromPackNeighborhood> received_data;
};
