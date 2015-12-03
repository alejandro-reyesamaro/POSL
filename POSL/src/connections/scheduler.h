#pragma once

#include "../solver/posl_solver.h"
#include "../tools/hash_map.h"

class Scheduler
{
    public:
        Scheduler(int _capacity);

        void checkOut();
        int schedule(std::shared_ptr<POSL_Solver> solver);
        void connect(std::shared_ptr<POSL_Solver> solver, ConnectorInfo connector, int pID);
        std::shared_ptr<POSL_Solver> getSolverAt(int i);
        int schedulerSize() { return solver_names.size(); }

    private:

        int process_base;
        int first_available_process;
        int capacity;
        std::vector<std::string> solver_names;        
        std::shared_ptr<HashMap<std::string, std::shared_ptr<POSL_Solver>>> solver_instances;
        std::vector<std::vector<std::pair<ConnectorInfo, int>>> connections;        
};
