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
  char inmsg, outmsg= 'a';
  MPI_Status status;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) 
  {
    dest = 1;
    source = 0;    
    rc = MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);    
    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    
    if(test_flag)
    {
      cout << "0 has a message" << endl;
      rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);      
      //rc = MPI_Get_count(&status, MPI_CHAR, &count);
      return 0;
    }
    else 
    {
      cout << "0 is done" << endl;
      exit(0);
    }
  } 
  else if (rank == 1) 
  {
    dest = 0;
    source = 1;
    rc = MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);    
    
    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
    
    if(test_flag)
    {
      cout << "1 has a message" << endl;
      rc = MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
      //rc = MPI_Get_count(&status, MPI_CHAR, &count);
      return 0;
    }
    else 
    {
      cout << "1 is done" << endl;
      exit(0);
    }
  }

  MPI_Finalize();
}

// TO COMPILE: mpic++.mpich -std=c++11 main.cpp -o mainmpi
// TO EXECUTE: mpiexec.mpich -np 2 ./mainmpi