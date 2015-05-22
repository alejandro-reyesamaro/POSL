#include "solution.h"

Solution::Solution(vector<Domain> _domains) : domains(_domains)
{
}

Solution::Solution(vector<Domain> _domains, vector<int> conf) : domains(_domains), configuration(conf)
{
}
