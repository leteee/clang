# CMake minimum version
cmake_minimum_required(VERSION 3.25)

# Project name
project (lang-c)

# CMAKE_VERSION
set(CMAKE_C_STANDARD 11)

# Excutable bin
add_executable(Server network_demo/epoll/server.c)
add_executable(Client network_demo/epoll/client.c)