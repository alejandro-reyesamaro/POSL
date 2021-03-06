#pragma once

#include <string>
#include <vector>

enum CM_type {SEQ_G, PAR_G, OM, OCH};

struct DeclarationInfo
{
    public :
        std::string name;
        int expantion;
        std::string keyword;
        std::string rest;
};

class CodingTools
{
    public:

        // computation strategy and solver
        static std::string extractDeclarationName(std::string code);
        static std::pair<std::vector<std::string>, std::vector<std::string>> extractModulesNamesFromDeclaration(std::string code);
        static std::string extractCompoundModuleCodeFromCS(std::string code);
        static void replace(std::string & code, std::vector<std::string> names, std::vector<std::string> instances);
        static std::string extractCSName(std::string code);

        // connections
        static std::string removeFirstConnection(std::string &code);

        static std::string textFromFile(std::string path);
        static std::pair<std::vector<std::string>, std::string> splitDeclarationConnectionsFromFile(std::string path);

        static std::pair<CM_type, std::string> extratModuleFromCM(std::string code);
        static std::string extractTypeFromToken(std::string code);
        static std::string extractNameFromToken(std::string code);
        static std::pair<std::string, std::string> extractInnerCode(std::string code,
                                                                    std::string open,
                                                                    std::string close,
                                                                    bool composite,
                                                                    bool strict);
        static std::pair<std::string, std::string> separateModules(std::string code, int hm);
        static std::pair<std::pair<std::string, std::string>, std::string> separateTokenAndCode(std::string code);
        static std::pair<std::string, std::string> extractExpressionsCommaSeparated(std::string code);
        static bool isInThere(std::string code, std::string word);
        static void trim(std::string & code);
        static std::vector<std::string> split_string(const std::string & s, char separator);
        static DeclarationInfo findDeclarationName(std::string code);
        static std::vector<std::string> extractDeclarationListFromKeyword(std::string code, std::string kw);
        static std::vector<std::string> expand_solvers_connections_declarations(std::vector<std::string> solvers_connectors);
};
