/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Converter
*/

#include "Converter.hpp"

namespace Process {

    /* CTOR & DTOR */

    Converter::Converter() : _error(false) {} ;

    /* PUBLIC METHODS */


    bool Converter::convert(const std::vector<std::string> &v)
    {
        if (!setupBegin())
            return false;

        return setupEnd();
    }

    /* PRIVATE METHODS */

    bool Converter::setupBegin()
    {
        if (!_f.setPath("rsrc/C/begin.txt"))
            return error("Missing file : " + _f.getPath() + " in rsrc!");

        for (const std::string &s : _f.getContent())
            _contC.push_back(s);

        return true;
    }

    bool Converter::setupEnd()
    {
        if (!_f.setPath("rsrc/C/end.txt"))
            return error("Missing file : " + _f.getPath() + " in rsrc!");

        for (const std::string &s : _f.getContent())
            _contC.push_back(s);

        return true;
    }

    bool Converter::checkValue(const std::string &s)
    {
        if (!isChar(s)
        && !isNb(s))
            return error("The value : " + s + " is not handled!");

        if (isNb(s))
            return true;

        for (const std::string &v : _contVar)
            if (s == v)
                return true;

        return error("The value : " + s + " is undefined!");
    }

    bool Converter::isDeclared(const std::string &s)
    {
        for (const std::string &v : _contVar)
            if (s == v)
                return true;
        return false;
    }

    bool Converter::isChar(const std::string &s) const
    {
        for (const char c : s)
            if (!((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')))
                return false;
        return true;
    }

    bool Converter::isNb(const std::string &s) const
    {
        for (const char c : s)
            if (!(c >= '0' && c <= '9'))
                return false;
        return true;
    }

    bool Converter::error(const std::string &s)
    {
        std::cerr << "\033[1;31m" << s << " è_é\033[0m" << std::endl;
        _error = true;
        return false;
    }

    /* THIS IS SHIT */

    bool Converter::redirect(const std::vector<std::string> &v)
    {
        _f.setPath("rsrc/C/" + v[0] + ".txt");
        if (!_f.isFile())
            return error("Missing file : " + _f.getPath() + " in rsrc!");

        if (v.size() == 3)
            std::cout << "2 args" << std::endl;
        else if (v.size() == 2)
            std::cout << "1 args" << std::endl;
        else
            std::cout << "0 args" << std::endl;
        return false;
    }

}
