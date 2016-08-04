#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <memory>

#include "../tools/tools.h"
#include "../tools/coding_tools.h"
#include "../solver/posl_meta_solver.h"
#include "../benchmarks/golfers.h"
#include "../benchmarks/n_queens.h"
#include "../benchmarks/costas_array.h"
#include "../benchmarks/golomb_ruler.h"

#include "mpi.h"

using namespace std;

#include <limits.h>
#include <unistd.h>

std::string getexepath()
{
	char result[ PATH_MAX ];
  	ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
  	return std::string( result, (count > 0) ? count : 0 );
}

int main(int argc, char *argv[])
{
    string tbench = argv[1];   
    string params = argv[2];    
	string path = argv[3];

	int comm_size;
	MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);

    shared_ptr<Benchmark> bench;

    string exe_path = getexepath();
    size_t p = exe_path.find_last_of('/');
    string log_path = exe_path.substr(0, p);

    if(tbench == "golfers")
    {
	    /* GOLFERS */
	    vector<string> v_params = CodingTools::split_string(params, '-');
	    int p = Tools::str2int(v_params[0]);
	    int g = Tools::str2int(v_params[1]);
	    int w = Tools::str2int(v_params[2]);
		shared_ptr<Golfers> gol(make_shared<Golfers>(p,g,w));
		bench = gol;
	}
	else if(tbench == "nqueens")
    {
	    /* N-QUEENS */	    
	    int n = Tools::str2int(params);
		shared_ptr<NQueens> gol(make_shared<NQueens>(n));
		bench = gol;
	}
	else if(tbench == "costas")
    {
	    /* COSTAS ARRAY */	    
	    int n = Tools::str2int(params);
		shared_ptr<CostasArray> gol(make_shared<CostasArray>(n));
		bench = gol;
	}
	else if(tbench == "golomb")
    {
	    /* GOLOMB */
	    vector<string> v_params = CodingTools::split_string(params, '-');
	    int o = Tools::str2int(v_params[0]);
	    int l = Tools::str2int(v_params[1]);
		shared_ptr<GolombRuler> gol(make_shared<GolombRuler>(o,l));
		bench = gol;
	}

	/* SQUARING SQUARE
	//vector<int> squares({6, 4, 4, 1, 3, 3, 3});
	//bench = new SquaringSquare(10, squares);
	vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
	bench = new SquaringSquare(110, squares);
	CreateSolverStrategy * css = new ForSquaringSquareCSS();
	solvers = css->create();
	*/

	/* GOLOMB RULER 
	//bench = new GolombRuler(12,85);
	//bench = new GolombRuler(8,34);
	bench = new GolombRuler(9,44);
	CreateSolverStrategy * css = new ForGolombRulerCSS();
	solvers = css->create();
	*/	

	try
	{
		//cout << "Meta-solver building" << endl;
	    shared_ptr<POSL_MetaSolver> s(make_shared<POSL_MetaSolver>(path, comm_size, bench, log_path));
	    //cout << "solving" << endl;
	    s->solve_in_parallel();
	}catch (const char* msg)
	{
	    cout << msg << endl;
	}

    MPI_Finalize();
}

/*
mpiexec.mpich -np 6 ./bin_par/POSL golfers 4-4-4 /home/reyesamaro-a/Documents/POSL/experiments201601/POSL_golfers\[no_comm\].posl
mpiexec.mpich -np 6 ./bin_par/POSL nqueens 300 /home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/POSL_nqueens.posl
mpiexec.mpich -np 6 ./bin_par/POSL costas 12 /home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/POSL_costas.posl
mpiexec.mpich -np 6 ./bin_par/POSL golomb 6-17 /home/reyesamaro-a/Documents/POSL/POSL/src/testers/test_codes/solver_golomb_test.posl
*/