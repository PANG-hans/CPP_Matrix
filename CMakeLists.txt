cmake_minimum_required(VERSION 3.17)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(Matrix include)
add_executable(MatrixTest include test/MatrixTest.cpp)
add_executable(MatrixConvolutionTest include test/MatrixConvolutionTest.cpp)