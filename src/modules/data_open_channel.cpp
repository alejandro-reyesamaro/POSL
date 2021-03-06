#include "data_open_channel.h"
#include "../tools/tools.h"

#include <iostream>
#include <ctime>

using namespace std;

DataOpenChannel::DataOpenChannel(string name, shared_ptr<Benchmark> _bench)
    : OpenChannel(name),
      contains_information(false),
      bench(_bench),
      logging(false),        // manually turn it on/of to log behavior
      process_logged(0),
      processes_to_log(1),  // manually insert the number of processes to wait for
      buffer(2 + _bench->Dimension() * 2),
      chrono(make_shared<Chronometer>())
{
    chrono->reset();
}

void DataOpenChannel::receive_and_log(int id, int tag, shared_ptr<PSP> psp)
{
    int pack_size;
    //psp->log("Receiving data");
    MPI_Get_count(&status, MPI_INT, &pack_size);
    //int * buffer = new int[pack_size];
    cout << "Op.Ch: PID = " << id <<". Receiving " << pack_size << "INT from " << status.MPI_SOURCE << endl;
    MPI_Recv(&buffer[0], pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);
    storeMessage(&buffer[0], psp);
    contains_information = true;
    cout << "Op.Ch: PID = " << id <<". Received " << endl;
    //cout << "Op.Ch: PID = "<< id <<". Received " << tag << endl;
    //logging = false;
    Tools::activateBit(process_logged, status.MPI_SOURCE);
}

shared_ptr<ComputationData> DataOpenChannel::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData>)
{    
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    int tag = dataID();
    //cout << "OPCh... " << tag << endl;

    int pack_size;
    int test_flag;

    MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);

    // just for debug
    //int times = 0;

#ifdef MST
    chrono->reset();
#endif
    while(test_flag)
    {
        if(!chrono->isRunning())
            chrono->start();

        if(logging)
            receive_and_log(id, tag, psp);
        else
        {
            //psp->log("Receiving data");
            MPI_Get_count(&status, MPI_INT, &pack_size);
            MPI_Recv(&buffer[0], pack_size, MPI_INT, status.MPI_SOURCE, tag, MPI_COMM_WORLD, &status);            
#ifdef MST
            sending_tick = buffer[pack_size-1];
            arriving_tick = clock();
            psp->report_traveling_package(arriving_tick - sending_tick);
            buffer.resize(pack_size-1);
#endif
            storeMessage(&buffer[0], psp);
            contains_information = true;
        }
        MPI_Iprobe(MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &test_flag, &status);
        //times ++;
    }
    if(logging && Tools::bitsCount(process_logged) >= processes_to_log) logging = false;

    //if(psp->GetPID() == 1)
    //    cout << "...OPCh" << times << endl;


    msg = selectMessage();
#ifdef MST
    if(chrono->isRunning())
        chrono->stop();
    //cout << chrono->TimeTics() << endl;
    psp->report_received_package(chrono->TimeTics());
#endif

    return msg;
    //return selectMessage();
}

/*
shared_ptr<ComputationData> DataOpenChannel::selectMessage()
{
    if (contains_information)
    {
        contains_information = false;
        return received_data;
    }
    else return nullptr;
}
*/
