cmake_minimum_required(VERSION 3.10)

project(reaction)
set(CMAKE_CXX_STANDARD 17)

set(
    SOURCE_FILE
    src/main.cc
    src/mainWindow.hpp

    src/utils/utils.hpp
    src/gui/window.cc
)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(main ${SOURCE_FILE})
target_link_libraries(main Qt6::Widgets)
