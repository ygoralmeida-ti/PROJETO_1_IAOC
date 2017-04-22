/**
*@file		main.cpp
*@breif		Arquivo principal do projeto para simulação de um pipeline de 5
*			estagios
*@author	Ygor Almeida (ygorgeofisico@gmail.com)
*@since		17/04/2017
*@date		17/04/2017
*/

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

#include "estrutura.h"
#include "processamento.h"

int main(void) {
	ifstream entrada("../data/pipe.txt");
	if(!entrada) {
		cerr << "O arquivo de entrada nao foi encontrado!" << endl;
		return 0;
	}

	string instruction;
	int countInstruction = 0;

	while(getline(entrada, instruction)) {
		
			countInstruction++;

	}
	//cout << "Instru: " << countInstruction << endl;

	Comando *lines = new Comando[countInstruction];

	entrada.clear();
	entrada.seekg(entrada.beg);

	int count = 0;
	string str1;

	while(count < countInstruction) {

		entrada >> lines[count].informacao[0];//lendo opcode

		if(lines[count].informacao[0] == "j") {
			getline(entrada, str1);
			cout << str1 << endl;
			lines[count].informacao[1]	= str1;
			lines[count].informacao[2] = "NaN";
			lines[count].informacao[3] = "NaN";
		} else if(lines[count].informacao[0] == "lw") {
			getline(entrada, str1, ' ');
			getline(entrada, str1, ',');
			cout << str1 << endl;
			lines[count].informacao[1]	= str1;
			getline(entrada, str1);			
			lines[count].informacao[2] = str1;
			lines[count].informacao[3] = "NaN";
		} else if(lines[count].informacao[0] == "sw") {
			getline(entrada, str1, ' ');
			getline(entrada, str1, ',');
			cout << str1 << endl;
			lines[count].informacao[1]	= str1;
			getline(entrada, str1);
			lines[count].informacao[2] = str1;
			lines[count].informacao[3] = "NaN";
		} else {

			cout << lines[count].informacao[0] << endl;
			cout << "==============================" << endl;

			for(int jj=1; jj<3; jj++) {
				getline(entrada, str1, ' ');
				getline(entrada, str1, ',');
				cout << str1 << endl;
				lines[count].informacao[jj]	= str1;
					
			}

			entrada >> lines[count].informacao[3];
			cout << lines[count].informacao[3] << endl;
			cout << "==============================" << endl;
		}
		
		++count;
	}

	entrada.close();

	processando(lines, countInstruction);

	delete[] lines;

	return 0;
}

	

