#include "posl_declaration_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "posl_solver_declaration.h"
#include "solver_declaration_uncoder.h"
#include "computation_strategy_uncoder.h"
#include "../tools/tools.h"

#include <iostream>

using namespace std;

POSL_DeclarationUncoder::POSL_DeclarationUncoder()
{}

HashMap<string, shared_ptr<POSL_Solver>> POSL_DeclarationUncoder::uncode(vector<string> vcode,
                                                                         std::shared_ptr<Benchmark> bench)
{
    HashMap<string, string> strategies;
    SolverDeclarationUncoder sd_unc;
    HashMap<string, shared_ptr<POSL_Solver>> solvers_list;

    size_t pos_br_clse;
    string strategy_name, strategy_code, solver_declar_code, code;
    PoslSolverDeclaration sdec;
    shared_ptr<POSL_Solver> solver;
    shared_ptr<ComputationStrategy> st_instance;

    for(unsigned int i = 0; i < vcode.size(); i++)
    {
        code = vcode[i];
        CodingTools::trim(code);
        string solver_name;
        while(!code.empty())
        {            
            DeclarationInfo p_info = CodingTools::findDeclarationName(code);
            //pos_2peq = code.find(":=");
            //pos_sp = code.find(' ', pos_2peq);
            //pos_2peq += 2;            
            pos_br_clse = code.find("}");
            if(p_info.keyword == SOLVER_KEYWORD)
            {                

                solver_declar_code = code.substr(0, pos_br_clse + 1);

                sdec = sd_unc.uncode(solver_declar_code);
                strategy_name = sdec.Computation_Strategy_Name;                
                if(strategies.existsKey(strategy_name))
                {
                    for(int k = 0; k < p_info.expantion; k++)
                    {
                        solver_name = sdec.Solver_Name + ((p_info.expantion > 1)
                                                         ? "__" + Tools::int2str(k+1)
                                                         : "");
                        strategy_code = strategies.mapOf(strategy_name);
                        st_instance = make_shared<ComputationStrategy>(strategy_name, strategy_code);
                        // The params would be introduced into the solver
                        shared_ptr<SearchProcessParamsStruct> psp_params = make_shared<SearchProcessParamsStruct>();
                        st_instance->Instantiate(sdec.Operation_Module_Instance_Names, sdec.Open_Channel_Instance_Names, bench, psp_params);
                        solver = make_shared<POSL_Solver>(solver_name, bench, st_instance, psp_params);
                        solvers_list.insert_or_replace(solver_name, solver);//push_back(solver);
                    }
                }
                else
                    throw "(POSL Exception) No such strategy declared (PoslUncoder::uncode) [" + strategy_name + "]";                
            }
            else if(p_info.keyword == CS_KEYWORD)
            {
                strategy_code = code.substr(0, pos_br_clse + 1);
                strategy_name = CodingTools::extractDeclarationName(strategy_code);
                strategies.insert_or_replace(strategy_name, strategy_code);

            }

            code = code.substr(pos_br_clse + 1);
            CodingTools::trim(code);
        }
    }

    return solvers_list;
}
