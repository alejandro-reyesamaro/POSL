#include "solution_data_open_channel.h"
#include "../data/dStrategy/solution_packing_strategy.h"


#include "mpi.h"

SolutionDataOpenChannel::SolutionDataOpenChannel()
{
}

ComputationData * SolutionDataOpenChannel::execute(PSP * psp, ComputationData * input)
{
    //Solution * s = dynamic_cast<Solution *>(input);
    //if (s == NULL)
    //throw "(POSL esception) Not casting allowed [SolutionDataOpenChannel.execute]";

    MPI_Status status;
    MPI_Request request;
    int pack_size;
    MPI_Probe(MPI_ANY_SOURCE, SOLUTION_PACKING_ID, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &pack_size);
    int * buffer = new int[pack_size];

    MPI_Irecv(buffer, pack_size, MPI_INT, MPI_ANY_SOURCE, SOLUTION_PACKING_ID, MPI_COMM_WORLD, &request);

    int test_flag;
    MPI_Test(&request, &test_flag, &status);

    if(test_flag) // Then, no data received
    {
        Solution * rSol = SolutionPackingStrategy::unpack(buffer, psp->GetBenchmark()->Domains());
        return rSol;
    }
    else return input;
}
