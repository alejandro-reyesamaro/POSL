#pragma once

#include "packer.h"
#include "../../data/neighborhood.h"

class NeighborhoodPacker : public Packer
{
    public:
        NeighborhoodPacker(std::vector<int> _config, int _neighborhood_size, int size_package, int size_body);

        std::vector<int> pack();

    protected:
        virtual void packBody() = 0;

        std::vector<int> configuration;
        int neighborhood_size;
        std::vector<int> body;
};
