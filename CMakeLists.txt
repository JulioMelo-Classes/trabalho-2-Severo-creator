cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "concordo", adiciona neste executável os arquivos src/concordo.cpp src/sistema.cpp src/executor.cpp
add_executable( concordo
                src/Concordo.cpp
                src/Sistema.cpp 
				src/Executor.cpp
                src/Usuario.cpp
                src/Servidor.cpp
                src/Canal.cpp
                src/Mensagem.cpp)

# The end
