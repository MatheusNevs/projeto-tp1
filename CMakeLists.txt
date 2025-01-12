cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(ProjetoTP1)

# Definição do padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os diretórios de inclusão
include_directories(include)
include_directories(lib)

# Adiciona os arquivos de origem
file(GLOB_RECURSE SOURCES "source/*.cpp" "lib/utils/*.cpp" "lib/db/sqlite3.cpp")

# Cria o executável
add_executable(ProjetoTP1 ${SOURCES})