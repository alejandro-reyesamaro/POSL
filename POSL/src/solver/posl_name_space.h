#pragma once

#include "../tools/hash_map.h"

#include <string>
#include <memory>

class POSL_NameSpace
{
    public:
        POSL_NameSpace();
        void newName(std::string name);
        int getID(std::string name);

    private:
        int id_counter;
        std::shared_ptr<HashMap<std::string, int>> hash_table;
};
