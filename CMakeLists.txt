cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp Model/RubiksCube33.cpp Model/RubiksCube33.h Model/RubiksCube3dArrayRep.cpp Model/RubiksCube1dArrayRep.cpp Model/RubiksCubeBitboard.cpp Model/RubiksCubeBitboard.cpp Model/RubiksCubeBitboard.cpp Solver/DFSSolver.h Solver/BFSsolver.h Solver/IDDFSsolver.h Solver/IDAStarSolver.h)
