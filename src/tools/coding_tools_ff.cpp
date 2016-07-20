#include "coding_tools.h"
#include "tokens_definition.h"

#include <fstream>
#include <sstream>

using namespace std;

///
/// \brief CodingTools::textFromFile Load the code from file
/// \param path
/// \return Code
///
string CodingTools::textFromFile(string path)
{
    string text = "";
    string line;
    ifstream infile(path);
    while (getline(infile, line))
    {
        CodingTools::trim(line);
        text = text + line + " ";
    }
    return text;
}

string load_cm_code(string line, string path)
{
    size_t pos_com = line.find("input");
    size_t pos_pc = line.find(';');
    pos_com += 5;
    string file_name = line.substr(pos_com, pos_pc - pos_com);
    CodingTools::trim(file_name);
    file_name += ".posl";
    size_t pos_last_bs = path.find_last_of('/');
    path = path.substr(0, pos_last_bs + 1) + file_name;
    return CodingTools::textFromFile(path);
}

///
/// \brief CodingTools::splitDeclarationConnectionsFromFile Split the declaration code and the communication code
/// \param path
/// \return pair.first: declaration code (strategies and solvers), pair.second: communication code (connections)
///
pair<vector<string>, string> CodingTools::splitDeclarationConnectionsFromFile(string path)
{
    string decl_text = "", conn_text = "", line;
    bool declaration_part = true;
    ifstream infile(path);
    size_t pos_conn_kw, pos_2p, pos_com;
    vector<std::string> declarations;
    while (getline(infile, line))
    {
        // extracting commentaries
        pos_com = line.find("//");
        if(pos_com != string::npos)
            line = line.substr(0, pos_com);

        // <input> filename
        if(line.find("input") != string::npos)
        {
            decl_text = decl_text + load_cm_code(line, path);
            continue;
        }

        CodingTools::trim(line);
        if(line == "};")
        {
            decl_text = decl_text + " } ";
            declarations.push_back(decl_text);
            decl_text = "";
            continue;
        }
        pos_conn_kw = line.find(CONNECTION_KW);
        if(pos_conn_kw != string::npos)
        {
            pos_2p = line.find(':', pos_conn_kw);
            line = line.substr(pos_2p + 1);
            declaration_part = false;
        }
        if(declaration_part)
            decl_text = decl_text + line + " ";
        else
            conn_text = conn_text + line + " ";
    }
    return { declarations, conn_text };
}
