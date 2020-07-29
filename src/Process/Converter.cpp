/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Converter
*/

#include "Converter.hpp"

namespace Process {

    /* CTOR & DTOR */

    Converter::Converter() : _error(false) { setupBegin(); }

    /* PUBLIC METHODS */

    bool Converter::convert(const std::vector<std::string> &v)
    {
        if (!redirect(v))
            return false;
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

    /* PRIVATE METHODS */

    bool Converter::setupBegin()
    {
        if (!_f.setPath("rsrc/C/begin.txt"))
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

    bool Converter::redirect(const std::vector<std::string> &v)
    {
        _f.setPath("rsrc/C/" + v[0] + ".txt");
        if (!_f.isFile())
            return error("Missing file : " + _f.getPath() + " in rsrc!");

        if (v.size() == 3)
            return transcript(v[1], v[2]);
        else if (v.size() == 2)
            return transcript(v[1]);
        return transcript();
    }

    std::string Converter::unslpit(const std::string &LV, const std::string &RV)
    {
        std::string tmp;
        bool b = false;

        for (const std::string &s : _f.getContent()) {
            if (s == " ") {
                if (b)
                    tmp += RV;
                else
                    tmp += LV;
                b = true;
            } else {
                tmp += s;
            }
        }
        return tmp;
    }

    std::string Converter::unslpit(const std::string &value)
    {
        std::string tmp;

        for (const std::string &s : _f.getContent()) {
            if (s == " ")
                tmp += value;
            else
                tmp += s;
        }
        return tmp;
    }

    bool Converter::transcript(const std::string &LV, const std::string &RV)
    {
        if (_f.getPath().find("GIMMEEEE") != std::string::npos)
            _contVar.push_back(LV);

        if (!checkValue(LV)
        || !checkValue(RV))
            return false;

        _contC.push_back("\t" + unslpit(LV, RV));
        return true;
    }

    bool Converter::transcript(const std::string &value)
    {
        if (!checkValue(value))
            return false;

        _contC.push_back("\t" + unslpit(value));
        return true;
    }

    bool Converter::transcript()
    {
        for (const std::string &s : _f.getContent())
            _contC.push_back("\t" + s);
        return true;
    }

}
