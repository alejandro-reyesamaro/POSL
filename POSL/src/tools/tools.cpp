#include "tools.h"
#include "tokens_definition.h"

#include <sstream>
#include <algorithm>

using namespace std;

std::string Tools::int2str(int c)
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
    string::size_type sz;
    float f = stof(str,&sz);
    return f;
}

bool Tools::isANumber(string str)
{
    //std::string::const_iterator it = s.begin();
    //while (it != s.end() && std::isdigit(*it)) ++it;
    //return !s.empty() && it == s.end();
    char* p;
    strtol(str.c_str(), &p, 10);
    return !(*p);
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

int Tools::segmentIntersection(int a1, int b1, int a2, int b2)
{
    int A = max(a1, a2);
    int b = min(b1, b2);
    return max(0, b - A);
}

vector<int> Tools::vector_possible_values_to_hold_sorted(unsigned int index, vector<int> current_configuration)
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
    std::srand(time(0));
    std::random_shuffle (vec.begin(), vec.end());
}

vector<int> Tools::generateMonotony(int N)
{
    //vector<int> v;
    //for(int i = 0; i < N; i++)
    //    v.push_back(i);
    //return v;

    vector<int> v(N);
    vector<int>::iterator it = v.begin();
    iota(it, it + N, 0);
    return v;
}

vector<int> Tools::generateMonotony(int a, int b)
{
    //vector<int> v;
    //if(a > b) return v;
    //for (int i = a; i <= b; i++)
    //    v.push_back(i);
    //return v;

    if(a > b) return vector<int>();
    int N = b - a + 1;
    vector<int> v(N);
    vector<int>::iterator it = v.begin();
    iota(it, it + N, a);
    return v;
}

void Tools::sortAscendent(vector<int> & v)
{
    sort(v.begin(), v.end());
}

T_Changes Tools::GetChanges(vector<int> config_before, vector<int> config_after)
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


