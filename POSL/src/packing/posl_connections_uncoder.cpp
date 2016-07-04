#include "posl_connections_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"

using namespace std;
POSL_ConnectionsUncoder::POSL_ConnectionsUncoder()
{
}

vector<ConnectionsDeclaration> POSL_ConnectionsUncoder::uncode(string code)
{
    CodingTools::trim(code);
    size_t pos_pc;
    vector<ConnectionsDeclaration> declars;
    int repetitions;

    vector<string> v_solvers_jacks, v_jacks, v_solvers_outlets, v_outlets, jacks_declar, outlets_declar;
    vector<string> dot_separated;
    pair<string, string> p;
    string declaration, rest;
    pair<pair<string, string>, string> p_op;

    while(!code.empty())
    {
        pos_pc = code.find(';');
        declaration = code.substr(0, pos_pc);
        code = code.substr(pos_pc + 1);

        p = CodingTools::extractInnerCode(declaration, "[", "]", false, true);
        jacks_declar = CodingTools::split_string(p.first, ',');

        // Expanding the solvers declarations
        jacks_declar = CodingTools::expand_solvers_connections_declarations(jacks_declar);
        // end expanding

        rest = p.second;
        CodingTools::trim(rest);
        if(rest.empty())
        {
            declars.push_back({OP_CONNECTION_NC_NAME, jacks_declar, v_jacks, v_solvers_outlets, v_outlets, 1});
            continue;
        }
        else if(Tools::isANumber(rest))
        {
            repetitions = Tools::str2int(rest);
            declars.push_back({OP_CONNECTION_NC_NAME, jacks_declar, v_jacks, v_solvers_outlets, v_outlets, repetitions});
            continue;
        }

        p_op = CodingTools::separateTokenAndCode(rest);
        p = CodingTools::extractInnerCode(p_op.second, "[", "]", false, true);
        outlets_declar = CodingTools::split_string(p.first, ',');

        // Expanding the solvers declarations
        outlets_declar = CodingTools::expand_solvers_connections_declarations(outlets_declar);
        // end expanding

        rest = p.second;
        CodingTools::trim(rest);
        if(jacks_declar.size() != outlets_declar.size())
            throw "(POSL Exception) Not matching connectors (PoslConnectionsUncoder::uncode_connections)";

        for(unsigned int i = 0; i < jacks_declar.size(); i++)
        {
            dot_separated = CodingTools::split_string(jacks_declar[i], '.');
            v_solvers_jacks.push_back(dot_separated[0]);
            v_jacks.push_back(dot_separated[1]);
            dot_separated = CodingTools::split_string(outlets_declar[i], '.');
            v_solvers_outlets.push_back(dot_separated[0]);
            v_outlets.push_back(dot_separated[1]);
        }
        if(rest.empty())
            declars.push_back({p_op.first.second, v_solvers_jacks, v_jacks, v_solvers_outlets, v_outlets, 1});
        else if(Tools::isANumber(rest))
        {
            repetitions = Tools::str2int(rest);
            declars.push_back({p_op.first.second, v_solvers_jacks, v_jacks, v_solvers_outlets, v_outlets, repetitions});
        }

        v_solvers_jacks.clear();
        v_jacks.clear();
        v_solvers_outlets.clear();
        v_outlets.clear();
    }

    return declars;
}
