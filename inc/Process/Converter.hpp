/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** Converter
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include "File.hpp"

namespace Process {

    class Converter final {

        public:

            Converter();
            ~Converter() = default;

            bool setup();

            std::string convert(const std::vector<std::string> &v);
            inline bool getError() const { return _error; }

        private:

            void redirect(const std::vector<std::string> &v);

            bool isChar(const std::string &s) const;
            bool isNb(const std::string &s) const;

        private:

            void ADDUWU(const std::string &LV, const std::string &RV) const;
            void SUWUB(const std::string &LV, const std::string &RV) const;
            void MUWUL(const std::string &LV, const std::string &RV) const;
            void DIVIDUWU(const std::string &LV, const std::string &RV) const;
            void MOWODULOWO(const std::string &LV, const std::string &RV) const;

            void GIMMEEEE(const std::string &LV, const std::string &RV) const;

            void PRINTOWO(const std::string &value) const;
            void PRINTUWU(const std::string &value) const;

            void CHECKUWU(const std::string &LV, const std::string &RV) const;
            void CHECKOWO(const std::string &LV, const std::string &RV) const;
            void WHILUWU(const std::string &LV, const std::string &RV) const;

            inline void YAMETEEE() { _contC.push_back( {"\treturn (84);"} ); }
            inline void UWU() { _contC.push_back( { "\treturn (0);"} ) ; }

        private:

            std::vector<std::string> _contVar;
            std::vector<std::string> _contC;

            Parsing::File _f;

            bool _error;

            char _itOWO = 0;
            char _itUWU = 0;

    };

}
