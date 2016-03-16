#include "../random_generator.h"

#include <chrono>

#include "mpi.h"

using namespace std;

int generate_seed()
{
	int myid = 0;
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    return chrono::system_clock::now().time_since_epoch().count() * (myid + 1);
}

RandomGenerator::RandomGenerator()
    : generator(generate_seed())
{}

int RandomGenerator::next_int(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

