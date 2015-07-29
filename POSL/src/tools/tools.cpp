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

int find_closed_char(string code, char open, char close)
{
    int count = 0;
    string::iterator it = code.begin();
    // *it == 'open' -> assumption
    count ++;
    it ++;
    int pos = 0;
    while (count != 0 &&  it != code.end())
    {
        if(*it == open) count ++;
        else if(*it == close) count --;
        pos ++;
        it ++;
    }
    return (count == 0) ? pos : -1;
}

string Tools::frontModule(string code) // code is TRIMED
{
    char front = code.front();
    string cm1_code = "";
    int pos = 0;
    switch(front)
    {
        case '[': // Parallel CM
            pos = find_closed_char(code, '[',']');
        break;
        case '{': // Sequential CM
            pos = find_closed_char(code, '{','}');
        break;
        default: // Operation Module
            pos = code.find_first_of(" ");
        break;
    }
    cm1_code = (pos != -1) ? code.substr(0, pos + 1) : code;
    return cm1_code;
}

int Tools::segmentIntersection(int a1, int b1, int a2, int b2)
{
    int A = max(a1, a2);
    int b = min(b1, b2);
    return max(0, b - A);
}
