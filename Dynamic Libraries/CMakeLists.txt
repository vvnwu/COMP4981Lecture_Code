cmake_minimum_required(VERSION 3.17.3)
project(dynamic_libraries C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include_directories(SYSTEM /usr/local/include)
link_directories(/usr/local/lib)

add_library(a SHARED library_a.c)
target_compile_options(a PRIVATE -Wpedantic -Wall -Wextra)

add_library(b SHARED library_b.c)
target_compile_options(b PRIVATE -Wpedantic -Wall -Wextra)

add_executable(main main.c)
target_link_libraries(main dc)
target_compile_options(main PRIVATE -Wpedantic -Wall -Wextra)
