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

    bool Converter::setup()
    {
        if (!_f.setPath("rsrc/C/begin.txt"))
            return false;

        for (const std::string &s : _f.getContent())
            _contC.push_back(s);

        return true;
    }

    std::string Converter::convert(const std::vector<std::string> &v)
    {
        return "";
    }

    /* PRIVATE METHODS */

    void Converter::redirect(const std::vector<std::string> &v)
    {
        if (v[0] == "ADDUWU")
            return ADDUWU(v[1], v[2]);
        else if (v[0] == "SUBUWU")
            return SUWUB(v[1], v[2]);
        else if (v[0] == "MUWUL")
            return MUWUL(v[1], v[2]);
        else if (v[0] == "DIVIDUWU")
            return DIVIDUWU(v[1], v[2]);
        else if (v[0] == "MOWODULOWO")
            return MOWODULOWO(v[1], v[2]);
        else if (v[0] == "GIMMEEEE")
            return GIMMEEEE(v[1], v[2]);
        else if (v[0] == "PRINTOWO")
            return PRINTOWO(v[1]);
        else if (v[0] == "PRINTUWU")
            return PRINTUWU(v[1]);
        else if (v[0] == "CHECKUWU")
            return CHECKUWU(v[1], v[2]);
        else if (v[0] == "CHECKOWO")
            return CHECKOWO(v[1], v[2]);
        else if (v[0] == "WHILUWU")
            return WHILUWU(v[1], v[2]);
        else if (v[0] == "YAMETEEE")
            return YAMETEEE();
        else if (v[0] == "UWU")
            return UWU();
    }

    bool Converter::isChar(const std::string &s) const
    {
        for (const char c : s)
            if ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'))
                return false;
        return true;
    }

    bool Converter::isNb(const std::string &s) const
    {
        for (const char c : s)
            if (c >= '0' && c <= '9')
                return false;
        return true;
    }

    /* THIS IS SHIT */

    void Converter::ADDUWU(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::SUWUB(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::MUWUL(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::DIVIDUWU(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::MOWODULOWO(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::GIMMEEEE(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::PRINTOWO(const std::string &value) const
    {
    }

    void Converter::PRINTUWU(const std::string &value) const
    {
    }

    void Converter::CHECKUWU(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::CHECKOWO(const std::string &LV, const std::string &RV) const
    {
    }

    void Converter::WHILUWU(const std::string &LV, const std::string &RV) const
    {
    }

}
