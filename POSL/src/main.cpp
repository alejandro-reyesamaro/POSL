#include "testers/include_testers.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "mpi.h"

using namespace std;

// Testing SEQUENTIAL
int main(int argc, char **argv)
{
    vector<shared_ptr<Tester>> tests;

    //tests.push_back(make_shared<Tester_LongInt>(argc, argv));
    //tests.push_back(make_shared<Tester_CostOfSolutionGolfers>(argc, argv));
    //tests.push_back(make_shared<Tester_CostOfSolutionSquaringSquare>(argc, argv));
    //tests.push_back(make_shared<Tester_CostOfSolutionGolomRules>(argc, argv));
    //tests.push_back(make_shared<Tester_CostOfSolutionNQueens>(argc, argv));

    //tests.push_back(make_shared<Tester_OneElementChangedNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_MultiElementsChangedNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_GolfersPermutationNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_MultiSortedChangesNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_OneSortedChangeNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_FromPackNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_UnionOperator>(argc, argv));

    //tests.push_back(make_shared<Tester_RandomOrderedConfGeneration>(argc, argv));
    //tests.push_back(make_shared<Tester_FlorianRandomConfigurationGeneration>(argc, argv));
    //tests.push_back(make_shared<Tester_RandomConfigurationGeneration>(argc, argv));
    //tests.push_back(make_shared<Tester_FirstImprovementSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_BestImprovementSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_RhoOperator>(argc, argv));
    //tests.push_back(make_shared<Tester_CyclicOperator>(argc, argv));
    //tests.push_back(make_shared<Tester_SetsIndexGenerator>(argc, argv));

    //tests.push_back(make_shared<Tester_ConditionalOperator>(argc, argv));
    //tests.push_back(make_shared<Tester_RandomSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_SimulatedAnnealingDecition>(argc, argv));
    //tests.push_back(make_shared<Tester_BestImprovementTabuSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_RandomPermutationConfigurationGeneration>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingSolution>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingDecisionPair>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingOneElementChangedNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingMultiChangesNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingGolfersPermutationNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingUnionNeighborhood>(argc, argv));

    //tests.push_back(make_shared<Tester_TabuSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_Solver_Golfers>(argc, argv));
    //tests.push_back(make_shared<Tester_Solver_GolombRuler>(argc, argv));
    //tests.push_back(make_shared<Tester_SolverSquaringSquare>(argc, argv));
    //tests.push_back(make_shared<Tester_SolverNQueens>(argc, argv));
    //tests.push_back(make_shared<Tester_IterationGolfers>(argc, argv));
    //tests.push_back(make_shared<Tester_CodingPOSL>(argc, argv));
    //tests.push_back(make_shared<Tester_PackingStrategies>(argc, argv));
    //tests.push_back(make_shared<Tester_AdaptiveSearchNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_GolfersASNeighborhood>(argc, argv));
    //tests.push_back(make_shared<Tester_ASRestart>(argc, argv));
    //tests.push_back(make_shared<Tester_BinarySearchTree>(argc, argv));
    //tests.push_back(make_shared<Tester_KBestImprovementSelection>(argc, argv));
    //tests.push_back(make_shared<Tester_Golfers1WeekNeighborhood>(argc, argv));

    //tests.push_back(make_shared<Tester_DanielRestart>(argc, argv));
    tests.push_back(make_shared<Tester_SolverCostasArray>(argc, argv));
    //tests.push_back(make_shared<Tester_CostOfSolutionCostasArray>(argc, argv));

    string output_str;
    //for(int k = 0; k < 25; k ++)
    for(unsigned int i = 0; i < tests.size(); i++)
    {
        try
        {
            output_str = tests[i]->test();
        }catch (const char* msg)
        {
             cout << msg << endl;
        }
        //cout << ">> " << output_str << endl;
        cout << output_str << endl;
    }
    return 0;
}

// Testing PARALLEL
int mainNOO(int argc, char **argv)
{
    vector<shared_ptr<Tester>> tests;

    //tests.push_back(make_shared<Tester_UnionOperator>(argc, argv));
    tests.push_back(make_shared<Tester_SpeedOperator>(argc, argv));

    int tester_id;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &tester_id);

    string output_str;
    for(unsigned int i = 0; i < tests.size(); i++)
    {
        output_str = tests[i]->test();
        cout << ">> " << output_str << endl;
    }

    MPI_Finalize();
    return 0;
}


// PARALLEL
// Compile command line:
// $ make

// Execute command line:
// $ mpiexec.mpich -np 2 ./bin/POSL
