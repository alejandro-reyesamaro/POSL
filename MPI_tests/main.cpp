#include "mpi.h"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

int main(int argc, char *argv[])
{
  int numtasks, rank, dest, source, rc, count, tag = 1; 
  int test_flag;
  char inmsg, outmsg= 'x';
  MPI_Status status;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) 
  {
    dest = 1;
    std::vector<char> v ({'a', 'b', 'c', 'e', 'f'});
    for (int i = 0; i < 5; i++)
    {    
      rc = MPI_Send(&v[i], 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
    }
  } 
  else if (rank == 1) 
  {
    source = 0;    
    this_thread::sleep_for (std::chrono::seconds(10));
    //for (int i = 0; i < 3; i++)
    //{
    //  rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);    
    //  rc = MPI_Get_count(&Stat, MPI_CHAR, &count);
    //}

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    while (test_flag)
    {
      rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
      rc = MPI_Get_count(&status, MPI_CHAR, &count);
      MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    }

    cout << "PID=1: " << inmsg << endl;
    //printf("Task %d: Received %d char(s) from task %d with tag %d \n",
      //rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG);
  }

  MPI_Finalize();
}

// TO COMPILE: mpic++.mpich -std=c++11 main.cpp -o mainmpi
// TO EXECUTE: mpiexec.mpich -np 2 ./mainmpi