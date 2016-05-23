#include "irregular_domain.h"
#include "../tools/tools.h"

using namespace std;

IrregularDomain::IrregularDomain(vector<int> _min_values, vector<int> _max_values)
    : min_values(_min_values),
      max_values(_max_values)
{
}

std::vector<int> IrregularDomain::GetValues(int variable)
{
    if(variable >= min_values.size())
        throw "(POSLException) Not valid variable index (IrregularDomain::GetValues)";
    return Tools::generateMonotony(min_values[variable], max_values[variable]);
}

int IrregularDomain::minimum(int variable)
{
    return min_values[variable];
}

int IrregularDomain::maximum(int variable)
{
    return max_values[variable];
}
