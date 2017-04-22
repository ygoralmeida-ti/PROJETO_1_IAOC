/**
*@file		estrutura.h
*@brief		Arquivo de cabecalho contendo a deficao de funcoes usadas no processamento
*@author	Ygor Almeida (ygorgeofisico@gmail.com)
*@since		17/04/2017
*@date		17/04/2017
*/

#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include "estrutura.h"

/**
*@brief 	Funcao que avalia as dependencias
*@param     *linhas ponteiro que aponta para lines
*@param     &countInstruction passarem por referencia de countInstruction
*@return	void
*/
void processando(Comando *linhas, int &countInstruction);

#endif