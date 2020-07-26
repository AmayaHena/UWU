cmake_minimum_required(VERSION 3.0)

project(UWU)

set(SRCS
    src/main.cpp
    )

set(HEADERS
    )

add_executable(UWU ${SRCS} ${HEADERS})
target_include_directories(UWU PUBLIC inc)
