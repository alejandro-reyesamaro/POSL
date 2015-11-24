#pragma once

#include <string>

enum CM_type {SEQ_G, PAR_G, OM, OCH};

class CodingTools
{
    public:
        static std::pair<CM_type, std::string> extratModuleFromCM(std::string code);
        static std::pair<std::string, std::string> extractExpressionsCommaSeparated(std::string code);
        static std::pair<std::string, std::string> decouplingNameCodeFromBE(std::string code);
        static std::string extractTypeFromToken(std::string code);
        static std::string extractNameFromToken(std::string code);

        static std::pair<std::string, std::string> extractExpressionAndCode1(std::string code);
        static std::pair<std::string, std::pair<std::string, std::string>> extractExpressionAndCode2(std::string code);
        static std::pair<std::string, std::pair<std::string, std::string>> extractNameAndCode2(std::string code);
        static std::pair<std::string, std::string> extractOChTokenAndName(std::string code);

        //static std::pair<std::string,std::string> decouplingExpressionCode(std::string code);

        static std::string textFromFile(std::string path);
        //static std::string frontModule(std::string code);
        static void trim(std::string & code);
};
