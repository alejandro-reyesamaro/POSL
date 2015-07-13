#include "tools.h"
#include <sstream>

string Tools::int2str(int c)
{
    std::string s = std::to_string(c);
    //ostringstream ss;
    //ss << c;
    //std::string s(ss.str());
    return s;
}
