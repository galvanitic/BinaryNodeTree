cmake_minimum_required(VERSION 3.17)
project(BinaryTrees)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinaryTrees main.cpp Employee.cpp Employee.h BinaryNode.cpp BinaryNode.h BinaryNodeTree.cpp BinaryNodeTree.h BinaryTreeInterface.h)