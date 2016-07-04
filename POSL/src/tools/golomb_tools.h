#pragma once

#include <vector>

class GolombTools
{
    public:
        static int max_posible_distances(int order, int length);
        static std::vector<int> vector_possible_values_to_hold_sorted(unsigned int index, std::vector<int> &current_configuration);
        static std::vector<int> subsum2golomb(std::vector<int> & golomb_config, int golomb_order);
        static std::vector<int> golomb2subsum(std::vector<int> & golomb_config, int golomb_order, int golomb_length);
};
