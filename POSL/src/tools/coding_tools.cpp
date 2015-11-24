#include "coding_tools.h"
#include "tokens_definition.h"

#include <boost/algorithm/string.hpp>
#include <fstream>

std::string CodingTools::textFromFile(std::string path)
{
    std::string text = "";
    std::string line;
    std::ifstream infile(path);
    while (getline(infile, line))
    {
        CodingTools::trim(line);
        text = text + line + " ";
    }
    return text;
}

// ///////////////////////////////////////////////////////
//! Private functions ////////////////////////////////////
///// ////////////////////////////////////////////////////
std::pair<std::string, std::string> decouplingExpressionCode(std::string code)
{
    size_t pos = code.find_first_of('(');
    size_t first = pos + 1;
    int count = 1;
    pos = code.find_first_of("()",pos + 1);
    size_t last = pos;
    while (pos != std::string::npos && count != 0)
    {
        if(code[pos] == '(') count ++;
        else if (code[pos] == ')') count --;
        last = pos;
        pos = code.find_first_of("()", pos + 1);
    }
    std::string expr = code.substr(first, last-first);
    std::string rest = code.substr(last + 1);
    return { expr, rest };
}

int find_closed_char(std::string code, std::string open, std::string close)
{
    int count = 0;
    std::string::iterator it = code.begin();
    // *it == 'open' -> assumption
    count ++;
    it ++;
    int pos = 0;
    std::string aux = "";
    while (count != 0 &&  it != code.end())
    {
        aux = {*it, *(it+1), *(it+2)};
        if(aux == open)
        {
            it += GROPER_OPEN_TOK_SIZE;
            pos += GROPER_OPEN_TOK_SIZE;
            count ++;
        }
        else if((aux + *(it+3)) == close)
        {
            it += GROPER_CLOSE_TOK_SIZE;
            pos += GROPER_CLOSE_TOK_SIZE;
            count --;
        }
        else
        {
            it ++;
            pos ++;
        }
    }
    return (count == 0) ? pos : -1;
}

std::pair<std::string, std::string> frontModule(std::string code, int hm) // code is TRIMED
{
    std::string front = code.substr(0, GROPER_OPEN_TOK_SIZE);
    std::string cm1_code = "";
    int pos = 0;

    if(front == PAR_TOK_OPEN) // Parallel CM
        pos = find_closed_char(code, PAR_TOK_OPEN,PAR_TOK_OPEN);
    else if(front == SEQ_TOK_OPEN) // Sequential CM
        pos = find_closed_char(code, SEQ_TOK_OPEN,SEQ_TOK_CLOSE);
    else pos = code.find_first_of(" ");
    cm1_code = (pos != -1) ? code.substr(0, pos + 1) : code;
    if (hm == 1)
        return { cm1_code, "" };
    else if (hm == 2)
        return { cm1_code, code.substr(pos + 1 ) };
    else
        throw "(POSL Exception) Not right call to function (CodingTools::frontModule)";
}
// ///////////////////////////////////////////////////////

std::pair<CM_type, std::string> CodingTools::extratModuleFromCM(std::string code)
{
    CodingTools::trim(code);
    int code_size = code.size();
    std::string front = code.substr(0, GROPER_OPEN_TOK_SIZE);
    std::string back  = code.substr(code_size - GROPER_CLOSE_TOK_SIZE, GROPER_CLOSE_TOK_SIZE);
    std::string sub_code = code.substr(GROPER_OPEN_TOK_SIZE, code.size() - (GROPER_OPEN_TOK_SIZE + GROPER_CLOSE_TOK_SIZE));

    // GROUPERS ---- '<S>.</S>': sequential, '<P>.</P>': parallel
    if (front == SEQ_TOK_OPEN && back == SEQ_TOK_CLOSE)
        return {SEQ_G, sub_code};
    else if (front == PAR_TOK_OPEN && back == PAR_TOK_CLOSE)
        return {PAR_G, sub_code};
    else
        return {OM, code};
}

std::pair<std::string, std::string> CodingTools::extractExpressionsCommaSeparated(std::string code)
{
    size_t pos = code.find_first_of('(');
    int count = 0;
    pos ++;
    size_t first = pos;
    size_t last = pos;
    while (pos != std::string::npos && (count != 0 || code[pos] != ','))
    {
        if(code[pos] == '(') count ++;
        else if (code[pos] == ')') count --;
        last = pos;
        pos ++;
    }
    std::string ex_1 = code.substr(first, last - first);
    pos++;
    first = pos;
    count = 0;
    while (pos != std::string::npos && (count != 0 || code[pos] != ')'))
    {
        if(code[pos] == '(') count ++;
        else if (code[pos] == ')') count --;
        last = pos;
        pos ++;
    }
    std::string ex_2 = code.substr(first, last - first);
    return {ex_1, ex_2};
}

std::pair<std::string, std::string> CodingTools::decouplingNameCodeFromBE(std::string code)
{
    CodingTools::trim(code);
    size_t pos_name = code.find('.') + 1;
    size_t pos_space = code.find_first_of(" ");
    std::string op_name = code.substr(pos_name, code.find(' ') - pos_name);
    std::string rest = code.substr(pos_space);
    CodingTools::trim(rest);
    return { op_name, rest };
}

std::string CodingTools::extractTypeFromToken(std::string code)
{
    CodingTools::trim(code);
    return code.substr(0, code.find('.'));
}

std::string CodingTools::extractNameFromToken(std::string code)
{
    CodingTools::trim(code);
    size_t pos_name = code.find('.') + 1;
    size_t pos_space = code.find_first_of(" ");
    return code.substr(pos_name, pos_space - pos_name);
}

std::pair<std::string, std::string> CodingTools::extractExpressionAndCode1(std::string code)
{
    std::pair<std::string, std::string> p1 = decouplingExpressionCode(code);
    std::string rest = p1.second;
    CodingTools::trim(rest);
    std::pair<std::string, std::string> p2 = frontModule(rest, 1);
    return {p1.first, p2.first};
}

std::pair<std::string, std::pair<std::string, std::string>> CodingTools::extractExpressionAndCode2(std::string code)
{
    std::pair<std::string, std::string> p1 = decouplingExpressionCode(code);
    std::string rest = p1.second;
    CodingTools::trim(rest);
    std::pair<std::string, std::string> p2 = frontModule(rest, 2);
    return { p1.first, p2 };
}


std::pair<std::string, std::pair<std::string, std::string>> CodingTools::extractNameAndCode2(std::string code)
{
    CodingTools::trim(code);
    int pos_name = code.find('.') + 1;
    int pos_space = code.find(' ');
    std::string op_name = code.substr(pos_name, pos_space - pos_name);
    std::string rest =  code.substr(pos_space + 1);
    CodingTools::trim(rest);
    std::pair<std::string, std::string> p = frontModule(rest, 2);
    return { op_name, p };
}

std::pair<std::string, std::string> CodingTools::extractOChTokenAndName(std::string code)
{
    CodingTools::trim(code);
    int pos_space = code.find(' ');
    std::string och_token = code.substr(0, pos_space);
    std::string rest =  code.substr(pos_space + 1);
    CodingTools::trim(rest);
    std::string name = code.substr(1, rest.size() - 2);
    CodingTools::trim(name);
    return { och_token, name };
}

void CodingTools::trim(std::string & code)
{
    boost::trim(code);
}
