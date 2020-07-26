/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <vector>

namespace Parsing {
    class Parser {

        public:

            Parser() = default;
            ~Parser() = default;

            bool checkHeaders(const std::vector<std::string> &v);

        private:

            std::vector<std::string> split(const std::string &s, const char delimiter = ' ') const;

    };

}