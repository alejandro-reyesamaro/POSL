#pragma once

#include <vector>

class GolombTools
{
    public:
        static int max_posible_distances(int order, int length);
        static std::vector<int> vector_possible_values_to_hold_sorted(unsigned int index, std::vector<int> &current_configuration);

};
