#include "tools.h"
#include <sstream>
#include <algorithm>

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

vector<int> Tools::vector_possible_values_to_hold_sorted(int index, vector<int> current_configuration)
{
    vector<int> posible_values;
    if(index == 0)
    {
        posible_values.push_back(0);
        return posible_values;
    }
    else if(index == current_configuration.size() - 1)
    {
        posible_values.push_back(current_configuration[current_configuration.size()-1]);
        return posible_values;
    }
    int a = current_configuration[index-1];
    int b = current_configuration[index+1];
    for(int i = a+1; i <= b-1; i++)
        if(i != current_configuration[index])
            posible_values.push_back(i);
    return posible_values;
}

int Tools::mismatches(vector<int> vector_1, vector<int> vector_2)
{
    int c = 0;
    for(unsigned int i = 0; i < vector_1.size(); i++)
        if(vector_1[i] != vector_2[i])
            c++;
    return c;
}

int * Tools::vector2array(vector<int> vec)
{
    int * buff = new int[vec.size()];
    copy(vec.begin(), vec.end(), buff);
    return buff;
}

void Tools::shuffle(vector<int> & vec)
{
    srand(time(0));
    random_shuffle (vec.begin(), vec.end());
}

vector<int> Tools::generateMonotony(int N)
{
    vector<int> v;
    for(int i = 0; i < N; i++)
        v.push_back(i);
    return v;
}

void Tools::sortAscendent(vector<int> & v)
{
    sort(v.begin(), v.end());
}
