cmake_minimum_required(VERSION 3.0)

project(UWU)

set(SRCS
    src/main.cpp
    src/Core.cpp

    src/Parsing/File.cpp
    src/Parsing/Parser.cpp
    )

set(HEADERS
    inc/Core.hpp

    inc/Parsing/File.hpp
    inc/Parsing/Parser.hpp
    )

add_executable(UWU ${SRCS} ${HEADERS})
target_include_directories(UWU PUBLIC
    inc/
    inc/Parsing/
)
