project(BookReader C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_COMPILER 11)
set(PROJECT_TARGET BookReader)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 3.10)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
# Create the executable
add_executable(${PROJECT_TARGET} main_app/app.c main_app/main_win.c main_app/main_win.h)
target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTK_LIBRARIES})

if (UNIX)
    set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
endif ()

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(${PROJECT_TARGET} PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTK_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTK_CFLAGS_OTHER})