#pragma once

#include "neighborhood.h"
#include "solution.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"
#include "../benchmarks/benchmark.h"
#include "../tools/fixed_size_vector.h"

class AdaptiveSearchPartialNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        AdaptiveSearchPartialNeighborhood(std::shared_ptr<Benchmark> _benchmark, int _part);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() { return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, vector<int> & _configuration);

    private:
        void updateChanges(std::shared_ptr<Randomizer> rand);
        int sickestVariableOnRange(std::shared_ptr<Randomizer> rand);
        void sickestVariables();

        std::shared_ptr<Benchmark> benchmark;
        int variables_to_analize;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        std::vector<int> monotony;
        std::vector<T_Changes> changes;

        //! A vector to store the dab variables (same projected cost)
        FixedSizeVector<int> bad_variables;
        vector<int> cost_n_variable;
};
