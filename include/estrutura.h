/**
*@file		estrutura.h
*@brief		Arquivo de cabecalho contendo a deficao de estruturas usadas
*@author	Ygor Almeida (ygorgeofisico@gmail.com)
*@since		17/04/2017
*@date		17/04/2017
*/

#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <string>
using std::string;

/**
*@brief		Estrutura para armezenar informacoes das linhas de comando
*/
struct Comando {
	string informacao[4];
};

struct Dependencia {
	int instrucao[2];
};

#endif