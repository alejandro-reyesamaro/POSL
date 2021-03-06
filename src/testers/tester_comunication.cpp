#include "tester_comunication.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../operators/operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../packing/packers/decision_pair_packer.h"
#include "../tools/tools.h"

#include "mpi.h"

Tester_Comunication::Tester_Comunication(int argc, char *argv[])
    : ARGC(argc), ARGV(argv)
{
}

void Tester_Comunication::test()
{
    int myid, comm_size, tag, pack_size;
    //MPI_Request request;
    MPI_Status status;

    MPI_Init(&ARGC, &ARGV);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));

    shared_ptr<Solution> sol1(make_shared<Solution>(bench->Variable_Domain(), Tester::Golfers_442_1s()));
    shared_ptr<Solution> sol2(make_shared<Solution>(bench->Variable_Domain(), Tester::Golfers_442_c0()));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    //bench->UpdateSolution(sol);

    int * buffer;

    if(myid == 0)
    {
        //ComputationData> pair(make_shared<DecisionPair(sol1, sol2);
        shared_ptr<DecisionPair> pair(make_shared<DecisionPair>(sol1, sol2));
        shared_ptr<DecisionPairPacker> p(make_shared<DecisionPairPacker>(pair));
        vector<int> package = p->pack();
        tag = package[0];
        pack_size = package.size();
        int dest = 1;
        buffer = &package[0];
        cout << tag << buffer[0] << endl;
        //MPI_Isend(&buffer, pack_size, MPI_INT, procID, tag, MPI_COMM_WORLD, &request);
        MPI_Send(buffer, pack_size, MPI_INT, dest, tag, MPI_COMM_WORLD);
    }
    else
    {
        int source = 0;
        MPI_Probe(0, DECISIONPAIR_PACKING_ID, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &pack_size);
        buffer = new int[pack_size];
        //cout << pack_size << endl;
        MPI_Recv(buffer, pack_size, MPI_INT, source, DECISIONPAIR_PACKING_ID, MPI_COMM_WORLD, &status);
        //MPI_Irecv(buffer, pack_size, MPI_INT, MPI_ANY_SOURCE, dataTag(), MPI_COMM_WORLD, &request);
        //MPI_Test(&request, &test_flag, &status);

        //cout << buffer[0] << endl;
        shared_ptr<DecisionPair> rPair(make_shared<DecisionPair>(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension()),
                                                                 make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())));
        rPair->updateFromPack(buffer);
        cout << rPair->GetFound()->configurationToString() << endl;
        delete[] buffer;
    }

    MPI_Finalize();
    /*




    int initial_cost = psp->GetBenchmark()->solutionCost(sol);


    CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration();
    CompoundModule> cm2(make_shared<OM_MultiElementsChangedNeighborhood();
    CompoundModule> cm3(make_shared<OM_BestImprovementTabuSelection();

    // cm1 |-> cm2 :
    Operator> op1(make_shared<SequentialExecOperator(cm1, cm2);

    // [cm1 |-> cm2] :
    GroupedComputation> G1(make_shared<GroupedSequentialComputation(op1);

    // [cm1 |-> cm2] |-> cm3 :
    Operator> op2(make_shared<SequentialExecOperator(G1, cm3);

    // [ [cm1 |-> cm2] |-> cm3 ] :
    GroupedComputation> G2(make_shared<GroupedSequentialComputation(op2);

    DecisionPair> pair;
    int cost = 0;

    for(int i = 0; i < 5; i++)
    {
        pair = (DecisionPair *)G2->execute(psp, sol);
        sol = pair->GetFound();
        cost = psp->GetBenchmark()->solutionCost(sol);
        psp->UpdateSolution(sol);
        cout << sol->configurationToString() << " - cost: " << cost << endl;
    }
    cout << endl;
    pair = (DecisionPair *)G2->execute(psp, sol);
    cout << pair->GetFound()->configurationToString() << endl;

    */
}
