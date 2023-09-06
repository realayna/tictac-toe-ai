cmake_minimum_required(VERSION 3.10)
project(TicTacToeAI)
set(CMAKE_CXX_STANDARD 17)

add_executable(tictac-toe-ai main.cpp)
include_directories(${CMAKE_SOURCE_DIR})

find_package(Threads REQUIRED)
target_link_libraries(tictac-toe-ai Threads::Threads)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
