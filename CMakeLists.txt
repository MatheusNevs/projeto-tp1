cmake_minimum_required(VERSION 3.10)
project(ProjetoTP1)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

include_directories(include lib)

file(GLOB SOURCES "source/*.cpp" "source/**/*.cpp" "lib/**/*.cpp")

add_executable(ProjetoTP1 ${SOURCES})

target_link_libraries(ProjetoTP1 PRIVATE SQLite::SQLite3)