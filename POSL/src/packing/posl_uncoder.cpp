#include "posl_uncoder.h"
#include "posl_declaration_uncoder.h"
#include "../tools/coding_tools.h"

using namespace std;

PoslUncoder::PoslUncoder()
{}

HashMap<string, shared_ptr<POSL_Solver>> PoslUncoder::uncode_declarations(string code, std::shared_ptr<Benchmark> bench)
{    
    POSL_DeclarationUncoder dec_unc;
    return dec_unc.uncode(code, bench);
}

vector<ConnectionsDeclaration> PoslUncoder::uncode_connections(string code, shared_ptr<Benchmark> bench)
{
    CodingTools::trim(code);
    while(!code.empty())
    {
        string line = CodingTools::removeFirstConnection(code);
        //string
    }
}

