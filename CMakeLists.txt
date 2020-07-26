cmake_minimum_required(VERSION 3.0)

project(UWU)

set(SRCS
    src/main.cpp
    src/Core.cpp

    src/Parsing/Parser.cpp
    src/Parsing/File.cpp
    )

set(HEADERS
    inc/Core.hpp

    inc/Parsing/Parser.hpp
    inc/Parsing/File.hpp
    )

add_executable(UWU ${SRCS} ${HEADERS})
target_include_directories(UWU PUBLIC
    inc/
    inc/Parsing/
)
