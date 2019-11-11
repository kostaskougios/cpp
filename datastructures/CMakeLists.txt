cmake_minimum_required(VERSION 3.10.0)
project(Testing)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

add_library(src src/person.cpp)
add_executable(tests tests/tests.cpp)

target_link_libraries(tests qt ${CONAN_LIBS} src)
