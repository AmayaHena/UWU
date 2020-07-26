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

    /* CTOR & DTOR */

    Parser::Parser() { _f.setPath("rsrc/keyword_list.txt"); }

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

    bool Parser::loadKeys()
    {
        if (!_f.isFile())
            return false;

        for (std::string &s : _f.getContent()) {
            std::vector<std::string> tmp = split(s);

            if (s.size() < 2)
                return false;
            _contKey.push_back(std::make_pair(tmp[0], tmp[1]));
        }
        return true;
    }

    std::vector<std::string> Parser::getKey(const std::string &s)
    {
        std::vector<std::string> v;

        if (s.empty())
            return v;
        v = split(s);
        if (v.empty()) {
            v.clear();
            return v;
        }

        for (std::pair<std::string, std::string> p : _contKey) {
            if (p.first == v[0]) {
                if (std::stoi(p.second) == static_cast<int>(v.size()) - 1) {
                    return v;
                } else {
                    std::cerr << "\033[1;31mERROR: bad number of arguments! è_é\033[0m" << std::endl;
                    std::cerr << s << std::endl;
                    _error = true;
                    break;
                }
            }
        }
        v.clear();
        return v;
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
