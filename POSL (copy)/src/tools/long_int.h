#pragma once

#include <algorithm>
#include <vector>
#include <string>


using namespace std;

class LongInt
{
    friend class MergedLongInt;
    public:
        LongInt(unsigned int _bytes, vector<int> _value);
        LongInt(unsigned int _bytes);
        LongInt(unsigned int _bytes, int _value);

        int length();

        LongInt operator|(LongInt &other);
        LongInt operator&(LongInt &other);

        bool activated();
        void activate(unsigned int bit);
        void activateAll();
        void deactivateAll();
        int bitCount();
        bool Equal(LongInt &other);
        string toString();
        bool clearBits();

    private:
        int bytes;
        vector<int> value;
};
