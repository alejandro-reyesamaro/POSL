#pragma once

class PackingStrategy
{
    public:
        virtual int * pack() = 0;
        virtual int BodySize() = 0;
        virtual int * body() = 0;
};
