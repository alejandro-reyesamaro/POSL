#pragma once

//#include "../data/computation_data.h"

#include "mpi.h"

#include <vector>

class Comunicator
{
    public:
        Comunicator();

        void sendMessage(std::vector<int> package, int procID);

    private:
        MPI_Request request;
};
