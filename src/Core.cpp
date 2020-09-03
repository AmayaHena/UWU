/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Core
*/

#include <stdlib.h>

#include "Core.hpp"

bool Core::run(const std::string &s)
{
    setup();
    if (!fileCheck(s)
    || !dataCheck()
    || !keysCheck())
        return false;

    Process::Converter c;

    for (std::string f : _f.getContent()) {
        if (!_p.getKey(f).empty()) {
            if (!c.convert(_p.getKey(f)))
                return false;
            if (_p.getError()
            || c.getError())
                return false;
        }
    }
    c.setupEnd();

    _f.setPath("main.c");
    _f.create(c.getContC());
    system("gcc main.c && rm main.c");

    std::cout << "\033[1;32mCompilation complete! UWU\033[0m\n";
    return true;
}

void Core::setup()
{
    if (!_f.setPath("rsrc/amaya_header.txt"))
        return;
    for (const std::string &s : _f.getContent())
        std::cout << s << std::endl;
}

bool Core::fileCheck(const std::string &s)
{
    if (!_f.setPath(s))
        return error("There is NOWO file!");

    if (_f.getExtension() != "UWU")
        return error("This not a UWU file!");

    return true;
}

bool Core::dataCheck()
{
    if (!_p.checkHeaders(_f.getContent()))
        return error("Your UWU(s) aren't good!");
    return true;
}

bool Core::keysCheck()
{
    if (!_p.loadKeys())
        return error("Missing keyword_lists.txt in rsrc!", true);
    return true;
}

bool Core::error(const std::string &s, bool b) const
{
    if (b)
        std::cerr << "\033[1;31mReclone the repo is recommended if you're missing ressources (rsrc)!\033[0m\n";
    std::cerr << "\033[1;31m" << s << " è_é\033[0m\n";
    return false;
}
