#include "tools.h"
#include <sstream>

string Tools::int2str(int c)
{
    string s = to_string(c);
    //ostringstream ss;
    //ss << c;
    //std::string s(ss.str());
    return s;
}

string Tools::float2str(float f)
{
    string s = to_string(f);
    return s;
}

int Tools::str2int(string str)
{
    string::size_type sz;   // alias of size_t
    int i_dec = std::stoi (str,&sz);
    return i_dec;
}

float Tools::str2float(string str)
{
    std::string::size_type sz;
    float f = stof(str,&sz);
    return f;
}

string Tools::configurationToString(vector<int> config)
{
    string txt = "[ ";
    vector<int>::iterator it = config.begin();
    txt += Tools::int2str(*it);
    it++;
    while ( it != config.end())
    {
        txt += ", " + Tools::int2str(*it);
        ++it;
    }
    return txt + " ]";
}
