#pragma once

class NeighborhoodBodyPackingStrategy
{
    public:
        virtual int bodySize() = 0;
        virtual int * packBody() = 0;
};
