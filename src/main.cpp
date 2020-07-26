/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** main
*/

#include <iostream>

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    Core c;

    if (!c.run(av[1]))
        return 84;

    return 0;
}
