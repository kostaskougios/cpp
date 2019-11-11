cmake_minimum_required(VERSION 3.10.0)
project(qt-test)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(include build/speech_autogen/include)

set(SPEECH src/mainwindow.cpp src/main.cpp)
qt5_wrap_ui(SPEECH ui/mainwindow.ui)
add_executable(speech ${SPEECH})

target_link_libraries(speech Qt5::Widgets)
