cmake_minimum_required(VERSION 3.6)
project(alg_p1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ClaseTiempo.cpp
    ClaseTiempo.hpp
    fibonacci.cpp
    fibonacci.hpp
    main.cpp
    Matrices.cpp funciones.cpp funciones.h)

add_executable(alg_p1 ${SOURCE_FILES})