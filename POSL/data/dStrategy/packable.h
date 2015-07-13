#pragma once

class Packable
{
    public :
        virtual int * pack() = 0;

        virtual int bodySize() = 0;
        virtual int * body() = 0;
};
