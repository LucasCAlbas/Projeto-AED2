cmake_minimum_required(VERSION 3.10)
project(RPG)

# Adicionar os arquivos de origem do projeto
add_executable(RPG src/main.cpp Lib/BaseCharacter.cpp Lib/Character.cpp Lib/Enemy.cpp Lib/Inventory.cpp Lib/Prop.cpp)

# Configurar opções de compilação e recursos do projeto
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Inclua o diretório da biblioteca raylib
include_directories(${CMAKE_SOURCE_DIR}/libs/raylib)

# Habilitar a compilação do código da biblioteca raylib
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/raylib)

# Adicione a biblioteca raylib como uma dependência
target_link_libraries(RPG raylib)
