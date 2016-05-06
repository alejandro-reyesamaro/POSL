#pragma once

#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"
#include "golomb_measures_struct.h"

#include <vector>
#include <memory>

class GolombRulerRelativeCostStructure : public ProjectableCost
{
    public:
        GolombRulerRelativeCostStructure(int _order, int _length);

        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void init(std::vector<int> config);
        int costOnVariable(int index);
        void reset();

        int Order, Length;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        void update_measures(std::vector<int> & configuration_before_chanche,
                             int new_pos,
                             int new_value,
                             std::vector<int> & measures,
                             bool updating);

        std::vector<int> aux_configuration;
        std::vector<int> measure_counters;
        std::vector<int> aux_measure_counters;
        std::shared_ptr<GolombMeasuresStruct> measure_per_variable;
};
