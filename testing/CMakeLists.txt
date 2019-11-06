cmake_minimum_required(VERSION 3.10.0)
project(Testing)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

add_library(whattotest src/whattotest.cpp)
add_executable(tests tests/tests.cpp)

target_link_libraries(tests ${CONAN_LIBS} whattotest)
