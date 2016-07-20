#pragma once

#include "../modules/om_golfers_custom_week_adaptive_search_neighborhood.h"

class OM_V_GolfersCustomWeekAS_Uncoder
{
    public:
        OM_V_GolfersCustomWeekAS_Uncoder();
        std::shared_ptr<OM_GolfersCustomWeekAdaptiveSearchNeighborhood> uncode(std::string code,
                                                                               std::shared_ptr<Benchmark> bench);
};
