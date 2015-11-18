#include "compound_module_uncoder.h"
#include "../tools/tools.h"
#include "grouped_sequential_computation_uncoder.h"
#include "grouped_parallel_computation_uncoder.h"
#include "operation_module_uncoder.h"

#define SEQ_TOK "<S>"
#define PAR_TOK "<P>"

using namespace std;

CompoundModuleUncoder::CompoundModuleUncoder()
{}

shared_ptr<CompoundModule> CompoundModuleUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    Tools::trim(code);
    int code_size = code.size();
    string front = code.substr(0, 3);
    string back  = code.substr(code_size - 3, 3);
    string sub_code = code.substr(3, code.size() - 6);

    // GROUPERS ---- '<S>.<S>': sequential, '<P>.<P>': parallel
    if (front == SEQ_TOK && back == SEQ_TOK)
    {
        GroupedSequentialComputationUncoder seq_unc;
        return seq_unc.uncode(sub_code, bench);
    }
    else if (front == PAR_TOK && back == PAR_TOK)
    {
        GroupedParallelComputationUncoder par_unc;
        return par_unc.uncode(sub_code, bench);
    }
    else
    {
        OperationModuleUncoder oper_unc;
        return oper_unc.uncode(code, bench);
    }
}
