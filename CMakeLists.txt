cmake_minimum_required(VERSION 3.0.0)
project(linked_list_test VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(linked_list_test main.c src/single_list.c)

include_directories(./inc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
