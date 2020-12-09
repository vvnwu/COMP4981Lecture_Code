cmake_minimum_required(VERSION 3.17.2)
project(fifo C)

set(CMAKE_C_STANDARD 11)

add_library( dc STATIC dc_fcntl.c dc_error.c dc_unistd.c dc_sys_stat.c)
target_compile_options(dc PRIVATE -Wpedantic -Wall -Wextra)

add_library( dc_verbose STATIC dc_verbose_fcntl.c dc_verbose_error.c dc_verbose_unistd.c dc_verbose_sys_stat.c)
target_compile_options(dc PRIVATE -Wpedantic -Wall -Wextra)

add_executable(server server.c)
target_link_libraries(server dc_verbose)
target_compile_options(server PRIVATE -Wpedantic -Wall -Wextra)

add_executable(client client.c)
target_link_libraries(client dc_verbose)
target_compile_options(client PRIVATE -Wpedantic -Wall -Wextra)
