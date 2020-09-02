/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Parser
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include "File.hpp"

namespace Parsing {
    class Parser final {

        public:

            Parser();
            ~Parser() = default;

            bool checkHeaders(const std::vector<std::string> &v);

            bool loadKeys();
            std::vector<std::string> getKey(const std::string &s);

            inline bool getError() const { return _error; }

        private:

            std::vector<std::string> split(const std::string &s, const char delimiter = ' ') const;

        private:

            File _f;
            std::vector<std::pair<std::string, std::string>> _contKey;

            bool _error = false;

    };

}