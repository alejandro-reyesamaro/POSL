#pragma once

#include <vector>
#include "../../tools/t_changes.h"
#include "../../tools/upper_matrix.h"

class SquaringSquareCostStructure
{
    public:
        SquaringSquareCostStructure(int _size, std::vector<int> _squares);

        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void set(std::vector<int> & _configuration);
        //int costOnVariable(int i);

        int Size;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        //! [Size of the big square]
        int size;
        //! [Sizes of the squares to put into the big one]
        std::vector<int> squares;

        UpperMatrix m_cost;
        std::vector<int> cost_on_variable_coefix;
        std::vector<int> cost_on_leaving;
        std::vector<int> momement_capacity;
};
