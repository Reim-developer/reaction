cmake_minimum_required(VERSION 3.10)
project(reaction)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

file(GLOB SRC_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

set(SRC
    src/main.c
    src/dropbox.c
    src/button.c
    src/components.c
    src/label.c
)

add_executable(main ${SRC})
target_include_directories(main PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${GTK4_LIBRARIES})
target_compile_options(main PRIVATE
    ${GTK4_CFLAGS_OTHER}
    -Wall -Wextra -Wpedantic -Werror
    -Wconversion -Wsign-conversion
    -Wshadow -Wformat=2 -Wundef
    -Wno-unused-parameter
)


