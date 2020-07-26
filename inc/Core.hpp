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

class Core {

    public:

        Core() = default;
        ~Core() = default;

        bool run(const std::string &s);

    private:

        bool fileCheck(const std::string &s);
        bool dataCheck();

        bool error(const std::string &s) const;

    private:

        Parsing::File _f;
        Parsing::Parser _p;

};
