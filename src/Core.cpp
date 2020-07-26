/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Core
*/

#include "Core.hpp"

bool Core::run(const std::string &s)
{
    if (!fileCheck(s)
    || !dataCheck())
        return false;

    std::cout << s << std::endl;
    return true;
}

bool Core::fileCheck(const std::string &s)
{
    if (!_f.setPath(s))
        return error("There is NOWO file! è_é");;

    if (_f.getExtension() != "UWU")
        return error("This not a UWU file! è_é");;

    return true;
}

bool Core::dataCheck()
{
    if (!_p.checkHeaders(_f.getContent()))
        return error("Your UWU(s) aren't good!");
    return true;
}


bool Core::error(const std::string &s) const
{
    std::cerr << s << std::endl;
    return false;
}

