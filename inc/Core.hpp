/*
** EPITECH PROJECT, 2020
** UWU
** File description:
** Core
*/

#pragma once

#include <iostream>

#include "File.hpp"

class Core {

    public:

        Core() = default;
        ~Core() = default;

        bool run(const std::string &s);

    private:

        Parsing::File _f;

};
