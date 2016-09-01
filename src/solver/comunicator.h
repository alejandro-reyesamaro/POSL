#pragma once

#include "mpi.h"

#include <vector>

//#define MST

class Comunicator
{
    public:
        Comunicator();

        void sendMessage(std::vector<int> & package, int procID, bool logging);

    private:
        MPI_Request request;

#ifdef MST
        std::vector<int> package_to_measure;
#endif
};
