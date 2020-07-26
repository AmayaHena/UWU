cmake_minimum_required(VERSION 3.0)

project(UWU)

set(SRCS
    src/main.cpp
    src/Core.cpp

    src/Process/Parser.cpp
    )

set(HEADERS
    inc/Core.hpp

    inc/Process/Parser.hpp
    )

add_executable(UWU ${SRCS} ${HEADERS})
target_include_directories(UWU PUBLIC
    inc/
    inc/Process/
)
