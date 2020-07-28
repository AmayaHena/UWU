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

            std::string convert();

        private:

        private:

            std::vector<std::string> _contVar;
            std::vector<std::string> _contC;

    };

}
