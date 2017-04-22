#Makefile for "Laboratorio 4" C++ application
#Created by Ygor Almeida 08/04/2017

RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR01=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Outras variaveis

# Opcoes de compilacao
CFLAGS01 = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR01)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: tarefa1

debug: CFLAGS01 += -g -O0
debug: tarefa1

# Alvo (target) para a construcao do executavel tarefa1
# Define os arquivos main.o e processamento.o como dependencias
tarefa1: $(OBJ_DIR)/main.o $(OBJ_DIR)/processamento.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS01) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel tarefa1 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto processamento.o
# Define o arquivo pŕocessamento.cpp e processamento.h como dependencias.
$(OBJ_DIR)/processamento.o: $(SRC_DIR)/processamento.cpp $(INC_DIR01)/processamento.h
	$(CC) -c $(CFLAGS01) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp e processamento.h como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR01)/processamento.h
	$(CC) -c $(CFLAGS01) -o $@ $<


#=======================================================================================

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/tarefa?/*