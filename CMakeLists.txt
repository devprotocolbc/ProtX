cmake_minimum_required(VERSION 3.31)
project(ProtX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/")

include_directories(ProtX/include)
include_directories(ProtX/source)
include_directories(SYSTEM ProtX/vendor/glad/include)

file(GLOB_RECURSE SOURCES "ProtX/source/*.cpp")          # DO NOT CHANGE THIS TO A MANUAL LIST .. unless necessary

add_executable(ProtX
        Main/Main.cpp
        ${SOURCES}
        ProtX/vendor/glad/src/glad.c
        ProtX/vendor/glad/src/glad_wgl.c)

target_link_libraries(${PROJECT_NAME} opengl32.lib)
