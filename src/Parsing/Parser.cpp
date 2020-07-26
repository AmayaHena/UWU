/*
** EPITECH PROJECT, 2020
** UWU
** File description:
** Parser
*/

#include "Parser.hpp"

#include <sstream>

#include "File.hpp"

namespace Parsing {

    /* PUBLIC METHODS */

    bool Parser::checkHeaders(const std::vector<std::string> &v)
    {
        Parsing::File f("rsrc/header.txt");

        if (!f.isFile())
            return false;

        std::vector<std::string> file = f.getContent();

        if (file.size() >= v.size())
            return false;

        for (size_t it = 0; it < file.size(); it++)
            if (file[it] != v[it])
                return false;

        size_t f_it = file.size() - 1;
        size_t v_it = v.size() - 1;

        while (f_it > 0)
            if (file[f_it--] != v[v_it--])
                return false;
        return true;
    }

    /* PRIVATE METHODS */

    std::vector<std::string> Parser::split(const std::string &s, const char delimiter) const
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
            tokens.push_back(token);
        return tokens;
    }

}
