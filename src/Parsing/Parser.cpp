/*
** EPITECH PROJECT, 2020
** UWU
** File description:
** Parser
*/

#include "Parser.hpp"

#include <sstream>

namespace Parsing {

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
