/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Converter
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include "File.hpp"

namespace Process {

    class Converter final {

        public:

            Converter();
            ~Converter() = default;

            bool convert(const std::vector<std::string> &v);
            inline bool getError() const { return _error; }

        private:

            bool setupBegin();
            bool setupEnd();

            bool checkValue(const std::string &s);
            bool isDeclared(const std::string &s);

            bool isChar(const std::string &s) const;
            bool isNb(const std::string &s) const;

            bool error(const std::string &s);

            bool redirect(const std::vector<std::string> &v);

        private:

            std::vector<std::string> _contVar;
            std::vector<std::string> _contC;

            Parsing::File _f;

            bool _error;

            // INC FEATURE
            /* char _itOWO = 0;
            char _itUWU = 0; */

    };

}
