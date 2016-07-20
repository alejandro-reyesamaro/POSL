#include "solver_declaration_uncoder.h"
#include "../tools/coding_tools.h"

using namespace std;

SolverDeclarationUncoder::SolverDeclarationUncoder()
{}

PoslSolverDeclaration SolverDeclarationUncoder::uncode(string code)
{    
    string solver_name = CodingTools::extractDeclarationName(code);
    CodingTools::trim(solver_name);
    string cs_name = CodingTools::extractCSName(code);
    CodingTools::trim(cs_name);
    pair<vector<string>, vector<string>> p_modules = CodingTools::extractModulesNamesFromDeclaration(code);
    return { solver_name, cs_name, p_modules.first, p_modules.second };

}
