#pragma once

#include <vector>
#include <list>

class GolombMeasuresStruct
{
    public:
        GolombMeasuresStruct(int size);

        void clear();
        void addVariableDistance(int variable_index, int distance);
        void removeDistanceFromVariable(int variable_index, int distance);
        int measuresOfVariable(int variable_index);

    private:
        std::vector<std::list<int>> measures;
        std::list<int> aux_measures;
};

