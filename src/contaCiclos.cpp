#include <iostream>
using std::cout;
using std::endl;

#include "estrutura.h"

void contaCiclos(Comando *linhas, Dependencia *info, int &countInstruction) {
	
	int count = 0;
	bool avaliaIF = true;
	while(count < countInstruction) {
			
		
	}

	//contar os ciclos

	/**cout <<"--------------------------------" << endl;
	while(count < countInstruction) {		
		
		cout << "Ciclo " << (ii+1) << endl;
		if(info[count].instrucao[0] == " " && info[count].instrucao[1] == " ") {
			cout << "IF:      ";

			if(linhas[count].informacao[0] == "add" || linhas[count].informacao[0] == "sub") {
				cout << linhas[count].informacao[0] << ", " << linhas[count].informacao[1] << ", " << linhas[count].informacao[2] << ", " << linhas[count].informacao[3] << endl;
			} else if(linhas[count].informacao[0] == "j") {
				cout << linhas[count].informacao[0] << ", " linhas[count].informacao[1] << endl;
			} else if(linhas[count].informacao[0] == "beq" || linhas[count].informacao[0] == "bne") {
				cout << linhas[count].informacao[0] << ", " << linhas[count].informacao[1] << ", " << linhas[count].informacao[2] << ", " << linhas[count].informacao[3] << endl;
			} else if(linhas[count].informacao[0] == "lw" || linhas[count].informacao[0] == "sw") {
				cout << linhas[count].informacao[0] << ", " << linhas[count].informacao[1] << ", " << linhas[count].informacao[2] << endl;
			}
		}




	}*/
}