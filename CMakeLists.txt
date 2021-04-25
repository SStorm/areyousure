cmake_minimum_required(VERSION 3.16)
project(areyousure C)

set(CMAKE_C_STANDARD 11)

add_definitions(-Werror -Wpedantic)
add_executable(areyousure areyousure.c)

install(TARGETS areyousure RUNTIME DESTINATION /usr/local/bin/)
