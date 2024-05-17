cmake_minimum_required(VERSION 3.26)
project(SortAnimation)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortAnimation main.cpp
        Sorting.cpp
        Sorting.h
        Renderer.cpp
        Renderer.h
        Button.cpp
        Button.h
        Utility.cpp
        Utility.h)
target_link_libraries(SortAnimation sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)