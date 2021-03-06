#pragma once

#include <algorithm>
#include <vector>
#include <string>

class LongInt
{
    friend class MergedLongInt;
    public:
        LongInt(unsigned int _bytes, std::vector<int> _value);
        LongInt(unsigned int _bytes);
        LongInt(unsigned int _bytes, int _value);

        int length();

        LongInt operator|(LongInt &other);
        LongInt operator&(LongInt &other);

        bool activated();
        bool activated(unsigned int bit);
        void activate(unsigned int bit);
        void activateAll();
        void deactivateAll();
        int bitCount();
        bool Equal(LongInt &other);
        std::string toString();

    private:
        int bytes;
        std::vector<int> value;
};
