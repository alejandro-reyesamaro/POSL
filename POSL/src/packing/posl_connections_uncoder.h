#pragma once

#include "../solver/posl_solver.h"
#include "../tools/hash_map.h"
#include "connections_declaration.h"

class POSL_ConnectionsUncoder
{
    public:
        POSL_ConnectionsUncoder();
        std::vector<ConnectionsDeclaration> uncode(std::string code);
};
