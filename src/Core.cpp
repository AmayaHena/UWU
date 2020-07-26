/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Core
*/

#include "Core.hpp"

bool Core::run(const std::string &s)
{
    if (!_f.setPath(s)
    || _f.getExtension() != "UWU")
        return false;

    std::cout << s << std::endl;

    return true;
}
