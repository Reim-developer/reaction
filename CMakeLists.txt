cmake_minimum_required(VERSION 3.10)
project(reaction)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

file(GLOB SRC_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

set(ABS_SRC_FILES "")
foreach(SRC ${SRC_FILES})
    list(APPEND ABS_SRC_FILES "${CMAKE_SOURCE_DIR}/${SRC}")
endforeach()

add_executable(main ${ABS_SRC_FILES})
target_include_directories(main PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${GTK4_LIBRARIES})
target_compile_options(main PRIVATE ${GTK4_CFLAGS_OTHER})


