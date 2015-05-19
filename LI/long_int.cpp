#include "long_int.h"
#include "merged_longint.h"

#include <iostream>
using namespace std;

LongInt::LongInt(unsigned int _bytes, vector<int> _value) : bytes(_bytes), value(_value)
{}

LongInt::LongInt(unsigned int _bytes, int _value) : bytes(_bytes)
{
    vector<int> aux (bytes, 0);
    aux[0] = _value;
    value = aux;
}

LongInt::LongInt(unsigned int _bytes) : LongInt(_bytes, 0) {}

int LongInt::length() { return (int)bytes; }

LongInt LongInt::operator|(LongInt &other)
{
    MergedLongInt m (*this, other);
    return m.long_or();
}

LongInt LongInt::operator&(LongInt &other)
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

void LongInt::activate(unsigned int bit)
{
    int act = (bit % 32) - 1;
    int byte = bit / 32;
    if (byte < length())
        value[byte] = value[byte] | (int)pow(2,act);
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
