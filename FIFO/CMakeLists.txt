cmake_minimum_required(VERSION 3.17)
project(FIFO C)

set(CMAKE_C_STANDARD 99)

add_executable(FIFO_client client.c)

add_executable(FIFO_server server.c)