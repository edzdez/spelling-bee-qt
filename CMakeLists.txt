cmake_minimum_required(VERSION 3.25)
project(spelling_bee_qt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Test
        REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)