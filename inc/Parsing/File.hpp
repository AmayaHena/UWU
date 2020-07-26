/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** File
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include <unistd.h>
    #include <bits/stdc++.h>

namespace Parsing {

    class File final {

        public:

            File() = default;
            File(const File &f);
            File(const std::string &path);
            ~File() noexcept;

            /* Change path */
            bool setPath(const std::string &path);

            /* Management */
            inline bool isFile() const noexcept { return access(_path.c_str(), F_OK ) != -1; }
            inline bool create() const noexcept { return createFile(); }
            bool create(const std::vector<std::string> &in) const noexcept;
            bool write(const std::vector<std::string> &in) const noexcept;
            bool rm() const noexcept;

            /* Getters */
            inline const std::string &getExtension() const { return _ext; }
            inline const std::string &getName() const { return _name; }
            inline const std::string &getPath() const { return _path; }
            std::vector<std::string> getContent() const;

        private:

            /* Create */
            bool createFile() const noexcept;

            /* Parsing */
            bool load() noexcept;
            size_t getLength(std::string &s) const;
            std::string parseName(std::string s) const;
            void parseExt(std::string s);

        private:

            std::string _ext;
            std::string _name;
            std::string _path;

    };

}
