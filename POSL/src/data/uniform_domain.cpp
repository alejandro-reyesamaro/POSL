#include "uniform_domain.h"
#include "../tools/tools.h"

UniformDomain::UniformDomain(int _min_value, int _max_value)
    : min_value(_min_value),
      max_value(_max_value)
{
}

std::vector<int> UniformDomain::GetValues(int)
{
    return Tools::generateMonotony(min_value, max_value);
}

int UniformDomain::minimum(int)
{
    return min_value;
}

int UniformDomain::maximum(int)
{
    return max_value;
}
