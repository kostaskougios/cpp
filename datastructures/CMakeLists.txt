cmake_minimum_required(VERSION 3.10.0)
project(Testing)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

add_library(src src/person.cpp)
add_executable(tests tests/tests.cpp)
target_link_libraries(tests ${CONAN_LIBS} src)


add_library(fc src/arraylist.cpp)
add_executable(arraylist-tests tests/arraylist-tests.cpp)
target_link_libraries(arraylist-tests ${CONAN_LIBS} fc)
