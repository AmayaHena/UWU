/*
** EPITECH PROJECT, 2020
** UWU
** File description:
** Core
*/

#pragma once

#include <iostream>

#include "File.hpp"
#include "Parser.hpp"

class Core final {

    public:

        Core() = default;
        ~Core() = default;

        bool run(const std::string &s);

    private:

        void setup();

        bool fileCheck(const std::string &s);
        bool dataCheck();
        bool keysCheck();

        bool error(const std::string &s, bool b = false) const;
        inline void print(const std::string &s) const;

    private:

        Parsing::File _f;
        Parsing::Parser _p;

};
