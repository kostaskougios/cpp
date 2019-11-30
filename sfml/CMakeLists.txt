cmake_minimum_required(VERSION 3.10.0)
project(sfml)

# set(CMAKE_VERBOSE_MAKEFILE TRUE)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(include)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/ball.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})
