#include "tools.h"
#include <sstream>

string Tools::int2str(int c)
{
    ostringstream ss;
    ss << c;
    std::string s(ss.str());
    return s;
}
