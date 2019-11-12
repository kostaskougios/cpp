cmake_minimum_required(VERSION 3.10.0)
project(qt-test)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS TextToSpeech REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(include build)

set(SPEECH src/mainwindow.cpp src/main.cpp)
qt5_wrap_ui(SPEECH ui/mainwindow.ui)
add_executable(speech ${SPEECH})

target_link_libraries(speech Qt5::Core Qt5::Widgets Qt5::TextToSpeech)
