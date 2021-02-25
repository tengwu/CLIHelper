cmake_minimum_required(VERSION 3.15)

project(test)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "start building test...")

include_directories(../)

link_directories(../out/)

add_executable(test main.cpp cmd1.cpp)

target_link_libraries(test CLIHelper)