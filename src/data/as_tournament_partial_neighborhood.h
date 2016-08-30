#pragma once

#include "neighborhood.h"
#include "dynamic_neighborhood.h"
#include "../tools/t_changes.h"
#include "dStrategy/apply_change_behavior.h"

class ASTournamentPartialNeighborhood
        : public Neighborhood,
          public DynamicNeighborhood,
          public std::enable_shared_from_this<Neighborhood>
{
    friend class ElementsChangeIterator;
    public:
        ASTournamentPartialNeighborhood(std::shared_ptr<Benchmark> _bench,
                                                    int _config_size,
                                                    int _players,
                                                    int _groups,
                                                    int _part);

        std::shared_ptr<POSL_Iterator> getIterator();
        int size() {return changes.size(); }
        std::vector<T_Changes> GetChanges() { return changes; }

        std::vector<int> neighborAt(int index);
        std::shared_ptr<FactoryPacker> BuildPacker();
        void Init(shared_ptr<PSP> psp, std::vector<int> & _configuration);

    private:
        void updateChanges(shared_ptr<Randomizer> rand);
        void save_swap(int pos1, int pos2);

        std::shared_ptr<Benchmark> benchmark;
        std::shared_ptr<ApplyChangeBehavior> changeAtBhv;
        int players, groups, periods;
        int part;
        std::vector<int> weeks_2_swap;
        std::vector<T_Changes> changes;
};
