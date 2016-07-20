#pragma once

#include "mpi.h"

#include <vector>

class Comunicator
{
    public:
        Comunicator();

        void sendMessage(std::vector<int> package, int procID, bool logging);

    private:
        MPI_Request request;
};
