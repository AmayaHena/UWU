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

            bool setupEnd();

            inline bool getError() const { return _error; }
            inline std::vector<std::string> getContC() const { return _contC; }

        private:

            bool setupBegin();

            bool checkValue(const std::string &s);
            bool isDeclared(const std::string &s);

            bool isChar(const std::string &s) const;
            bool isNb(const std::string &s) const;

            bool error(const std::string &s);

        private:

            bool redirect(const std::vector<std::string> &v);

            std::string unslpit(const std::string &LV, const std::string &RV);
            std::string unslpit(const std::string &value);

            bool transcript(const std::string &LV, const std::string &RV);
            bool transcript(const std::string &value);
            bool transcript();

        private:

            std::vector<std::string> _contVar;
            std::vector<std::string> _contC;

            Parsing::File _f;

            bool _error;

    };

}
