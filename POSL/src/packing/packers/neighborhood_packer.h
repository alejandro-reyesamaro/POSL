#pragma once

#include "packer.h"
#include "../../data/neighborhood.h"

class NeighborhoodPacker : public Packer
{
    public:
        NeighborhoodPacker(vector<int> _config, int _neighborhood_size, int size_package, int size_body);
        vector<int> pack();

    protected:
        virtual void packBody() = 0;

        vector<int> configuration;
        int neighborhood_size;
        vector<int> body;
};
