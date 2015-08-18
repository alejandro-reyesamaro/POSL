#pragma once

#include "../data/dStrategy/packable.h"

#include "mpi.h"

#include <vector>

class Comunicator
{
    public:
        Comunicator();

        void sendMessage(Packable *data, int procID);

    private:
        MPI_Request request;
};
