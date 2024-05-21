cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp RubiksCube33.cpp RubiksCube33.h RubiksCube3dArrayRep.cpp)
