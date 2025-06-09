cmake_minimum_required(VERSION 3.31)
project(ProtX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")

include_directories(ProtX/include)
include_directories(ProtX/source)

file(GLOB_RECURSE SOURCES "ProtX/Source/*.cpp")          # DO NOT CHANGE THIS TO A MANUAL LIST .. unless necessary

add_executable(ProtX
        Game/Main.cpp
        ${SOURCES})
