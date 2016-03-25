#include "long_int.h"
#include "merged_longint.h"

#include <iostream>
#include <math.h>
#include <limits>
#include <algorithm>

using namespace std;

LongInt::LongInt(unsigned int _bytes, vector<int> _value) : bytes(_bytes), value(_value)
{}

LongInt::LongInt(unsigned int _bytes, int _value)
    : bytes(_bytes),
      value(_bytes)
{    
    fill(value.begin(), value.end(), 0);
    value[0] = _value;
}

LongInt::LongInt(unsigned int _bytes)
    : bytes(_bytes),
      value(_bytes)
{
    activateAll();
}

int LongInt::length() { return (int)bytes; }

LongInt LongInt::operator|(LongInt & other)
{
    MergedLongInt m (*this, other);
    return m.long_or();
}

LongInt LongInt::operator&(LongInt & other)
{
    MergedLongInt m (*this, other);
    return m.long_and();
}

bool LongInt::activated()
{
    bool act = false;
    for(int i = 0; i < length(); i++)
        act = act || (value[i] > 0);
    return act;
}

bool LongInt::activated(unsigned int bit)
{
    //int act = max(0,int((bit % 32) - 1));
    //int act = (bit % 32) - 1;
    int act = (bit % 32);
    int byte = bit / 32;
    int activated_bit = (int)pow(2,act);
    if (byte < length())
    {
        int is_activated = value[byte] & activated_bit;
        return (is_activated != 0);
    }
    else return false;
}

void LongInt::activate(unsigned int bit)
{
    //int act = max(0,int((bit % 32) - 1));
    //int act = (bit % 32) - 1;
    int act = (bit % 32);
    int byte = bit / 32;
    if (byte < length())
        value[byte] = value[byte] | (int)pow(2,act);
}

void LongInt::activateAll()
{
    int l = numeric_limits<int>::max();
    fill(value.begin(), value.end(), l);
    //vector<int> aux (bytes, std::numeric_limits<unsigned int>::max());
    //value = aux;
}
void LongInt::deactivateAll()
{
    fill(value.begin(), value.end(), 0);
    //vector<int> aux (bytes, 0);
    //value = aux;
}

int LongInt::bitCount()
{
    int count = 0;

    for(int i = 0; i < length(); i++){
        int v = value[i];
        v = v - ((v >> 1) & 0x55555555);
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
        count += (((v + (v >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
    return count;
}

bool LongInt::Equal(LongInt &other)
{
    MergedLongInt m (*this, other);
    return m.equal();
}

string binary(unsigned int val, int bit)
{
    if(bit == 0)
        return "";

    string str_b = ((val & 1) == 1) ? "|" : ".";
    return binary(val >> 1, bit - 1) + str_b;
}

string LongInt::toString()
{
    string bin = "";
    for(vector<int>::iterator it = value.begin(); it != value.end(); ++it)
        bin = binary(*it, 32) + bin;
    return bin;
}
