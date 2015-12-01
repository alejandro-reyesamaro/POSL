#include "posl_declaration_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "posl_solver_declaration.h"
#include "solver_declaration_uncoder.h"
#include "computation_strategy_uncoder.h"
using namespace std;

POSL_DeclarationUncoder::POSL_DeclarationUncoder()
{}

HashMap<string, shared_ptr<POSL_Solver>> POSL_DeclarationUncoder::uncode(string code, std::shared_ptr<Benchmark> bench)
{
    HashMap<string, string> strategies;
    SolverDeclarationUncoder sd_unc;
    HashMap<string, shared_ptr<POSL_Solver>> solvers_list;

    size_t pos_2peq, pos_br, pos_br_clse;
    string type_declar, strategy_name, strategy_code, solver_declar_code;
    PoslSolverDeclaration sdec;
    shared_ptr<POSL_Solver> solver;
    shared_ptr<ComputationStrategy> st_instance;

    CodingTools::trim(code);
    while(code.empty())
    {
        pos_2peq = code.find(":=");
        pos_br = code.find("{", pos_2peq);
        pos_2peq += 2;
        type_declar = code.substr(pos_2peq, pos_br - pos_2peq);
        if(type_declar == SOLVER_KEYWORD)
        {
            pos_br_clse = code.find("}", pos_br);
            solver_declar_code = code.substr(0, pos_br_clse + 1);
            sdec = sd_unc.uncode(solver_declar_code);
            strategy_name = sdec.Computation_Strategy_Name;
            if(strategies.existsKey(strategy_name))
            {
                strategy_code = strategies.mapOf(strategy_name);
                st_instance = make_shared<ComputationStrategy>(strategy_name, strategy_code);
                st_instance->Instantiate(sdec.Operation_Module_Instance_Names, sdec.Open_Channel_Instance_Names, bench);
                solver = make_shared<POSL_Solver>(bench, st_instance);
                solvers_list.insert(sdec.Solver_Name, solver);//push_back(solver);
            }
            else
                throw "(POSL Exception) No such strategy declared (PoslUncoder::uncode) [" + strategy_name + "]";
            code = code.substr(pos_br_clse + 1);
        }
        else if(type_declar == CS_KEYWORD)
        {
            pos_br_clse = code.find("}", pos_br);
            strategy_code = code.substr(0, pos_br_clse + 1);
            strategy_name = CodingTools::extractDeclarationName(strategy_code);
            strategies.insert(strategy_name, strategy_code);
            code = code.substr(pos_br_clse + 1);
        }

        CodingTools::trim(code);
    }

    return solvers_list;
}
