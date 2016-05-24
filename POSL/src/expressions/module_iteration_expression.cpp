#include "module_iteration_expression.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include <iostream>

using namespace std;

ModuleIterationExpression::ModuleIterationExpression(int _iterations)
    : iterations(_iterations)
{}

bool ModuleIterationExpression::evaluate(shared_ptr<PSP> psp)
{
    int costsofar = psp->BestCostSoFar();
    if(costsofar < 0)
        costsofar = 1; // making true the second expression
    int iter = psp->GetIterations();
    bool resp = (psp->GetIterations() % iterations != 0 && costsofar > 0);
    return (psp->GetIterations() % iterations != 0 && costsofar > 0);
}

string ModuleIterationExpression::codeToSend()
{
    return string(BE_MODULE_ITERATIONS_TOK) + " " + Tools::int2str(iterations); // "IterMod"
}
