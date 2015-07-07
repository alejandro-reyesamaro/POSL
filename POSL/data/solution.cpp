#include "solution.h"
#include "tools/tools.h"

Solution::Solution(vector<Domain> _domains) : domains(_domains)
{
}

Solution::Solution(vector<Domain> _domains, vector<int> conf) : domains(_domains), configuration(conf)
{
}

bool Solution::equal(Solution * other)
{
    if (other->configuration.size() != configuration.size())
        return false;
    for(unsigned int i = 0; i < configuration.size(); i++)
        if (other->configuration[i] != configuration[i])
            return false;
    return true;
}

string Solution::configurationToString()
{
    string txt = "[ ";
    vector<int>::iterator it = configuration.begin();
    txt += Tools::int2str(*it);
    it++;
    while ( it != configuration.end())
    {
        txt += ", " + Tools::int2str(*it);
        ++it;
    }
    return txt + " ]";
}
