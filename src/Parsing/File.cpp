/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** File
*/

#include <fstream>
#include <stdio.h>

#include "File.hpp"

namespace Parsing {

    /* CTOR & DTOR */

    File::File(const File &f) { setPath(f.getPath()); }

    File::File(const std::string &path) : _path(path) { load(); }

    File::~File()
    {
        _ext.clear();
        _name.clear();
        _path.clear();
    }

    /* PUBLIC METHODS */

    bool File::setPath(const std::string &path)
    {
        if (path.empty()
        || path == _path)
            return false;
        _name.clear();
        _ext.clear();
        _path = path;
        return load();
    }

    bool File::create(const std::vector<std::string> &in) const noexcept
    {
        if (!createFile() || _path.empty())
            return false;
        return write(in);
    }

    bool File::write(const std::vector<std::string> &in) const noexcept
    {
        if (!isFile() || _path.empty())
            return false;

        std::ofstream f(_path);

        for (const std::string &s : in)
            f << s << std::endl;
        f.close();

        return true;
    }

    bool File::rm() const noexcept
    {
        if (!isFile() || _path.empty())
            return false;
        if (remove(_path.c_str()) != 0)
            return false;
        return true;
    }

    std::vector<std::string> File::getContent() const
    {
        std::vector<std::string> cont;
        std::fstream f(_path);
        if (!f || _path.empty())
            return cont;

        std::string tmp;
        while(std::getline(f, tmp))
            cont.push_back(tmp);
        f.close();
        return cont;
    }

    /* PRIVATE METHODS */

    bool File::createFile() const noexcept
    {
        if (isFile())
            return false;

        std::ofstream f(_path);
        f.close();

        if (!isFile())
            return false;

        return true;
    }

    bool File::load() noexcept
    {
        parseExt(_path);
        _name = parseName(_path);
        if (!isFile())
            return false;
        return true;
    }

    size_t File::getLength(std::string &s) const
    {
        size_t p = s.find_last_of("/") + 1;

        for (size_t n = p; s[n]; n++)
            if (s[n] == '.')
                return n - p;
        return p;
    }

    std::string File::parseName(std::string s) const
    {
        if (s.find(".") == std::string::npos
        && s.find("/") == std::string::npos)
            return s;

        if (s.find(".") != std::string::npos) {
            if (s.find("/") == std::string::npos)
                return s.substr(0, s.find_last_of("."));
            else
                return s.substr(s.find_last_of("/") + 1, getLength(s));
        }
        return s.substr(s.find_last_of("/") + 1, s.size());
    }

    void File::parseExt(std::string s)
    {
        if (s.find(".") == std::string::npos)
            _ext.clear();

        std::reverse(s.begin(), s.end());

        s = s.substr(0, s.find_first_of("."));
        std::reverse(s.begin(), s.end());
        _ext = s;
    }

}
