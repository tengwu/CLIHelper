cmake_minimum_required(VERSION 3.15)
project(CLIHelper)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    ADD_DEFINITIONS(-D_DEBUG)
endif()

add_library(CLIHelper CMDFactory.cpp CMDFactory.h ICMDBase.cpp ICMDBase.h IParamParser.cpp IParamParser.h IConsoleListener.cpp IConsoleListener.h IOutput.cpp IOutput.h Config.cpp Config.h ParamSet.cpp ParamSet.h)

add_subdirectory(test)