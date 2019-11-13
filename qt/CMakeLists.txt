cmake_minimum_required(VERSION 3.10.0)
project(qt-test)

# C++ standards
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Qt config
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOUIC_SEARCH_PATHS src ui)

# Qt packages
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS TextToSpeech REQUIRED)

# build
include_directories(include build)

set(SPEECH src/mainwindow.cpp src/main.cpp)
add_executable(speech ${SPEECH})

target_link_libraries(speech Qt5::Core Qt5::Widgets Qt5::TextToSpeech)
