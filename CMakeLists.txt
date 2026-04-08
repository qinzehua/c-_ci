cmake_minimum_required(VERSION 3.16)
project(simple_clock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(simple_clock 86/test.cpp)

if(MSVC)
  target_compile_options(simple_clock PRIVATE /utf-8)
endif()
