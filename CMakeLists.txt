cmake_minimum_required(VERSION 3.8)
project(mephi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sequence.h LinkedList.h ArrayList.h Tests.h TestArray.h TestLinked.h)
add_executable(mephi ${SOURCE_FILES})