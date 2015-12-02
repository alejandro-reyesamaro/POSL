#include "coding_tools.h"
#include "tokens_definition.h"

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>

///
/// \brief CodingTools::textFromFile Load the code from file
/// \param path
/// \return Code
///
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


///
/// \brief CodingTools::splitDeclarationConnectionsFromFile Split the declaration code and the communication code
/// \param path
/// \return pair.first: declaration code (strategies and solvers), pair.second: communication code (connections)
///
std::pair<std::vector<std::string>, std::string> CodingTools::splitDeclarationConnectionsFromFile(std::string path)
{
    std::string decl_text = "";
    std::string conn_text = "";
    bool declaration_part = true;
    std::string line;
    std::ifstream infile(path);
    size_t pos_conn_kw;
    size_t pos_2p;
    std::vector<std::string> declarations;
    while (getline(infile, line))
    {
        CodingTools::trim(line);
        if(line == "};")
        {
            decl_text = decl_text + " } ";
            declarations.push_back(decl_text);
            decl_text = "";
            continue;
        }
        pos_conn_kw = line.find(CONNECTION_KW);
        if(pos_conn_kw != std::string::npos)
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

///
/// \brief extractInnerCode Extract the code between delimiters
/// \param code
/// \param open Open delimiter. <P> for example
/// \param close Close delimiter. <\P> for example
/// \param composite If we have to assume that there are more delimiters inside
/// \param strict If we want just the code inside or also de delimiters
/// \return pair.first: inner code, pair.second: the rest
///
std::pair<std::string, std::string> CodingTools::extractInnerCode(std::string code, std::string open, std::string close, bool composite, bool strict)
{
    size_t pos_begin;
    size_t pos_end;
    if(!composite)
    {
        pos_begin = (strict) ? code.find(open) + open.size() : code.find(open);
        pos_end = (strict) ? code.find(close) - 1 : code.find(close) + close.size() - 1;
    }
    else
    {
        int count = 0;
        pos_begin = code.find(open);
        size_t pos = pos_begin + 1;
        count ++;
        size_t pos_o, pos_c;
        while (count != 0 &&  pos != std::string::npos)
        {
            pos_o = code.find(open, pos);
            pos_c = code.find(close, pos);
            pos_end = (pos_o < pos_c && pos_o != std::string::npos) ? pos_o : pos_c;
            count += (pos_o < pos_c && pos_o != std::string::npos) ? 1 : -1;
            pos = pos_end + 1;
        }
        if (count == 0)
        {
            if (strict)
            {
                pos_begin += open.size();
                pos_end --;
            } else pos_end = pos_end + close.size() - 1;
        } else  return { code, "" };
    }
    std::string inner_code = code.substr(pos_begin, pos_end - pos_begin + 1);
    std::string rest = (strict) ? code.substr(pos_end + close.size() + 1) : code.substr(pos_end + 1);
    return {inner_code, rest};
}

///
/// \brief findDeclarationName Extract the name and the keyword in a declaration header
/// \param code
/// \return pair.first.first: name, pair.firs.second: keyword, pair.second.first: header, pair.second.second: rest
///
std::pair<std::pair<std::string, std::string>, std::string> CodingTools::findDeclarationName(std::string code)
{
    std::string asign = ":=";
    size_t pos_2peq = code.find(asign);
    std::string name = code.substr(0, pos_2peq);
    CodingTools::trim(name);
    std::string rest = code.substr(pos_2peq + asign.size());
    CodingTools::trim(rest);
    size_t pos_esp = rest.find(' ');
    std::string kw = rest.substr(0, pos_esp);
    CodingTools::trim(kw);
    rest = rest.substr(pos_esp + 1);
    return {{name, kw}, rest };
}


///
/// \brief extractDeclarationListFromKeyword Extracting the modules or the channel list in the declaration
/// \param code
/// \param km Keyword
/// \return The list of words
///
std::vector<std::string> CodingTools::extractDeclarationListFromKeyword(std::string code, std::string kw)
{
    std::vector<std::string> l;
    size_t pos_kw = code.find(kw);
    if(pos_kw != std::string::npos)
    {
        std::pair<std::string, std::string> p = CodingTools::extractInnerCode(code.substr(pos_kw), ":", ";", false , true);
        l = CodingTools::split_string(p.first, ',');
    }
    return l;
}

///
/// \brief CodingTools::separateModules Separates modules of an operator
/// \param code
/// \param hm Arity of the operator
/// \return pair.first: module 1, pair.second: module 2 (if hm = 2) or "" (if hm = 1)
///
std::pair<std::string, std::string> CodingTools::separateModules(std::string code, int hm)
{
    CodingTools::trim(code);
    std::string front = code.substr(0, GROPER_OPEN_TOK_SIZE);
    std::string cm1_code = "";
    std::string cm2_code = "";

    if(front == PAR_TOK_OPEN) // Parallel CM
    {
        std::pair<std::string, std::string> p = CodingTools::extractInnerCode(code, PAR_TOK_OPEN, PAR_TOK_CLOSE, true, false);
        cm1_code = p.first;
        cm2_code = (hm == 1) ? "" : p.second;
    }
    else if(front == SEQ_TOK_OPEN) // Parallel CM
    {
        std::pair<std::string, std::string> p = CodingTools::extractInnerCode(code, SEQ_TOK_OPEN, SEQ_TOK_CLOSE, true, false);
        cm1_code = p.first;
        cm2_code = (hm == 1) ? "" : p.second;
    }
    else
    {
        size_t pos = code.find_first_of(" ");
        cm1_code = (pos != std::string::npos) ? code.substr(0, pos + 1) : code;
        cm2_code = (hm == 1) ? "" : code.substr(pos + 1 );
    }
    return { cm1_code, cm2_code };
}

///
/// \brief CodingTools::extratModuleFromCM Remove the groupers (e.g. <P> and </P>) if there are
/// \param code
/// \return pair.first: what kind of module it is (grouped, OM or OCh), pair.second: the code inside (returns 'code' if is a OM or an OCh)
///
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
    else if (front == OCH_TOK)
        return {OCH, code};
    else
        return {OM, code};
}

///
/// \brief CodingTools::extractExpressionsCommaSeparated Extract the boolean expressions separated by commas
/// \param code
/// \return 2 boolean expressions
///
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

///
/// \brief CodingTools::extractTypeFromToken Extract just the type of a token
/// \param code
/// \return Token's type
///
std::string CodingTools::extractTypeFromToken(std::string code)
{
    CodingTools::trim(code);
    return code.substr(0, code.find('.'));
}

///
/// \brief CodingTools::extractNameFromToken Extract just the name of a token
/// \param code
/// \return Token's name
///
std::string CodingTools::extractNameFromToken(std::string code)
{
    CodingTools::trim(code);
    size_t pos_name = code.find('.') + 1;
    size_t pos_space = code.find_first_of(" ");
    return code.substr(pos_name, pos_space - pos_name);
}


///
/// \brief CodingTools::separateTokenAndCode Separates the token (e.g. OP.Min) and the module(s)
/// \param code
/// \return pair.first.first: token type (OP, BE, etc..), pair.first.second: token name (e.g. |->), pair.second: modules code (rest)
///
std::pair<std::pair<std::string, std::string>, std::string> CodingTools::separateTokenAndCode(std::string code)
{
    CodingTools::trim(code);
    size_t pos_space = code.find(" ");
    std::string cms_code = code.substr(pos_space + 1);
    std::string token = code.substr(0, pos_space);
    size_t pos_p = token.find('.');
    std::string tk_type = token.substr(0, pos_p);
    std::string tk_name = token.substr(pos_p + 1);
    return {{ tk_type, tk_name}, cms_code};
}

void CodingTools::trim(std::string & code)
{
    boost::trim(code);
}

///
/// \brief CodingTools::split_string Split the string taking into account the separator
/// \param s String
/// \param delim Char separator
/// \return The string list
///
std::vector<std::string> CodingTools::split_string(const std::string & s, char separator)
{
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, separator)) {
        CodingTools::trim(item);
        elems.push_back(item);
    }
    return elems;
}










// computation strategy and solver

std::string CodingTools::extractDeclarationName(std::string code)
{
    std::string name = code.substr(0, code.find_first_of(":="));
    CodingTools::trim(name);
    return name;
}

std::pair<std::vector<std::string>, std::vector<std::string>> CodingTools::extractModulesNamesFromDeclaration(std::string code)
{
    size_t pos_kw_om = code.find(CS_OM_KEYWORD);
    size_t pos_2p;
    size_t pos_pc;
    std::vector<std::string> oms;
    std::vector<std::string> ochs;
    std::string str;

    if (pos_kw_om == std::string::npos)
        pos_2p = 0;
    else
    {
        pos_2p = code.find(':', pos_kw_om);
        pos_pc = code.find(';', pos_2p);
        pos_2p ++;
        str = code.substr(pos_2p, pos_pc - pos_2p);
        oms = CodingTools::split_string(str, ',');
    }

    size_t pos_kw_ch = code.find(CS_OCH_KEYWORD);

    if (pos_kw_ch != std::string::npos)
    {
        pos_2p = code.find(':', pos_kw_ch);
        pos_pc = code.find(';', pos_2p);
        pos_2p ++;
        str = code.substr(pos_2p, pos_pc - pos_2p);
        ochs = CodingTools::split_string(str, ',');
    }
    return { oms, ochs };
}

std::string CodingTools::extractCompoundModuleCodeFromCS(std::string code)
{
    size_t pos_open = code.find("{");
    size_t pos_close = code.find("}");
    pos_open ++;
    std::string cm_code = code.substr(pos_open, pos_close - pos_open);
    CodingTools::trim(cm_code);
    return cm_code;
}

void CodingTools::replace(std::string & code, std::vector<std::string> names, std::vector<std::string> instances)
{
    std::string n_str;
    for(int i = 0; i < names.size(); i++)
    {
      n_str = names[i];
      CodingTools::trim(n_str);
      size_t pos = code.find(n_str + " ");
      while(pos != std::string::npos)
      {
          code.replace(pos, n_str.size(), instances[i]);
          pos = code.find(n_str + " ", pos + 1);
      }
    }
}

std::string CodingTools::extractCSName(std::string code)
{
    size_t pos_kw_cs = code.find(CS_KEYWORD);
    size_t pos_2p = code.find(':', pos_kw_cs);
    size_t pos_pc = code.find(';', pos_2p);
    pos_2p ++;
    std::string cs_name = code.substr(pos_2p, pos_pc - pos_2p);
    return cs_name;
}

// connections

std::string CodingTools::removeFirstConnection(std::string & code)
{
    size_t pos_pc = code.find(';');
    std::string line = code.substr(0, pos_pc + 1);
    code = code.substr(pos_pc + 1);
    CodingTools::trim(code);
    return line;
}
