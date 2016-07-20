#pragma once

#include "../../tools/t_changes.h"
#include "../../tools/upper_matrix.h"
#include "projectable_cost.h"

#include <vector>
#include <memory>

class SquaringSquareCostStructure : public ProjectableCost
{
    public:
        //! Default constructor.
        /*!
            \param _size Size of the big square.
            \param _squares Sizes of the squares.
         */
        SquaringSquareCostStructure(int _size, std::vector<int> _squares);


        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void set(std::vector<int> _configuration);
        int costOnVariable(int index);

        int CurrentCost;
        std::vector<int> Configuration;

    private:
        int relative_cost(UpperMatrix & matrix_cost,
                          std::vector<int> & current_config,
                          std::vector<int> & new_config,
                          T_Changes & change,
                          int current_cost,
                          std::vector<int> & cost_on_variable_vector,
                          std::vector<int> & cost_on_leaving_vector);

        //! [Size of the big square]
        int size;
        //! [Sizes of the squares to put into the big one]
        std::vector<int> squares;

        UpperMatrix m_cost;
        UpperMatrix m_cost_aux;
        std::vector<int> configuration_aux;
        std::vector<int> cost_on_variable;
        std::vector<int> cost_on_variable_aux;
        std::vector<int> cost_on_leaving;
        std::vector<int> cost_on_leaving_aux;
        std::vector<int> momement_capacity;
};
