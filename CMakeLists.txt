cmake_minimum_required(VERSION 3.10)

project(reaction)
set(CMAKE_CXX_STANDARD 17)

set(
    SOURCE_FILE
    src/main.cc
    src/mainWindow.hpp

    src/utils/utils.hpp
    src/utils/utils.cc

    src/gui/window.cc

    src/gui/label.cc
    src/gui/include/label.hpp

    src/gui/buttons.cc
    src/gui/include/buttons.hpp

    src/gui/include/dropbox.hpp
    src/gui/dropbox.cc

    src/common/include/signal.hpp
    src/common/include/props.hpp

    src/common/context.cc
    src/common/include/context.hpp
)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(main ${SOURCE_FILE})

target_compile_options(main PRIVATE "$<$<CXX_COMPILER_ID:Clang>:-fno-direct-access-external-data>")

target_link_libraries(main Qt6::Widgets)
