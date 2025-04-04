cmake_minimum_required(VERSION 3.10)
project(reaction_helper)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PARTED REQUIRED libparted)
set(
    SOURCE

    sys/core.c
    sys/fat32.c

    cmd.c
    main.c 
)

add_executable(helper ${SOURCE})
target_include_directories(helper PRIVATE ../ ${PARTED_INCLUDE_DIRS})
target_link_libraries(helper PRIVATE ${PARTED_LIBRARIES})
target_compile_options(helper PRIVATE ${PARTED_CFLAG_OTHER})
