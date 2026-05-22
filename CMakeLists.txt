cmake_minimum_required(VERSION 4.2.4)
project(mini-bank-account-system)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror -Wpedantic -Wconversion -Wshadow)

add_executable(main src/main.cpp)
