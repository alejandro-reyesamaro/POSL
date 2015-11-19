#include "tools.h"
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>

using namespace std;

std::string Tools::int2str(int c)
{
    std::string s = to_string(c);
    //ostringstream ss;
    //ss << c;
    //std::string s(ss.str());
    return s;
}

std::string Tools::float2str(float f)
{
    std::string s = to_string(f);
    return s;
}

int Tools::str2int(string str)
{
    std::string::size_type sz;   // alias of size_t
    int i_dec = std::stoi (str,&sz);
    return i_dec;
}

float Tools::str2float(string str)
{
    std::string::size_type sz;
    float f = stof(str,&sz);
    return f;
}

std::string Tools::configurationToString(vector<int> config)
{
    std::string txt = "[ ";
    std::vector<int>::iterator it = config.begin();
    txt += Tools::int2str(*it);
    it++;
    while ( it != config.end())
    {
        txt += ", " + Tools::int2str(*it);
        ++it;
    }
    return txt + " ]";
}

int find_closed_char(std::string code, char open, char close)
{
    int count = 0;
    std::string::iterator it = code.begin();
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

std::string Tools::frontModule(std::string code) // code is TRIMED
{
    char front = code.front();
    std::string cm1_code = "";
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

std::vector<int> Tools::vector_possible_values_to_hold_sorted(unsigned int index, std::vector<int> current_configuration)
{
    std::vector<int> posible_values;
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

int Tools::mismatches(std::vector<int> vector_1, std::vector<int> vector_2)
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
    std::copy(vec.begin(), vec.end(), buff);
    return buff;
}

void Tools::shuffle(std::vector<int> & vec)
{
    std::srand(time(0));
    std::random_shuffle (vec.begin(), vec.end());
}

std::vector<int> Tools::generateMonotony(int N)
{
    std::vector<int> v;
    for(int i = 0; i < N; i++)
        v.push_back(i);
    return v;
}

std::vector<int> Tools::generateMonotony(int a, int b)
{
    std::vector<int> v;
    if(a > b) return v;
    for (int i = a; i <= b; i++)
        v.push_back(i);
    return v;
}

void Tools::sortAscendent(vector<int> & v)
{
    std::sort(v.begin(), v.end());
}

void Tools::trim(std::string & code)
{
    boost::trim(code);
}

T_Changes Tools::GetChanges(std::vector<int> config_before, std::vector<int> config_after)
{
    vector<int> ch_possitions;
    vector<int> ch_values;
    pair<vector<int>::iterator,vector<int>::iterator> p;
    vector<int>::iterator pp;

    p = mismatch (config_before.begin(), config_before.end(), config_after.begin());

    int new_value, pos_mismatch = 0;

    while(p.first != config_before.end())
    {
        pos_mismatch = p.first - config_before.begin();
        new_value = * p.second;

        ch_possitions.push_back(pos_mismatch);
        ch_values.push_back(new_value);

        ++p.first; ++p.second;

        p = mismatch (p.first, config_before.end(), p.second);
    }
    T_Changes changes = {ch_possitions, ch_values, ch_possitions.size()};
    return changes;
}

std::string Tools::textFromFile(std::string path)
{
    std::string text = "";
    std::string line;
    std::ifstream infile(path);
    while (getline(infile, line))
    {
        text = text + line + " ";
    }
    return text;
}
