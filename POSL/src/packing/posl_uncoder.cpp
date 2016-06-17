#include "posl_uncoder.h"
#include "posl_declaration_uncoder.h"
#include "posl_connections_uncoder.h"


using namespace std;

PoslUncoder::PoslUncoder()
{}

HashMap<string, shared_ptr<POSL_Solver>> PoslUncoder::uncode_declarations(vector<string> code,
                                                                          std::shared_ptr<Benchmark> bench,
                                                                          shared_ptr<SearchProcessParamsStruct> psp_params)
{    
    POSL_DeclarationUncoder dec_unc;
    return dec_unc.uncode(code, bench, psp_params);
}

vector<ConnectionsDeclaration> PoslUncoder::uncode_connections(string code)
{
    POSL_ConnectionsUncoder conn_unc;
    return conn_unc.uncode(code);
}

