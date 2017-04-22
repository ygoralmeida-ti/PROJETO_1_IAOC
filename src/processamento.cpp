/**
*@file		processamento.cpp
*@brief		Arquivo de corpo contendo a implementacao de funcao que avalia a pipeline
*			para o conjunto de instrucoes fornecidas
*@author	Ygor Almeida (ygorgeofisico@gmail.com)
*@since		17/04/2017
*@date		17/04/2017
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include "processamento.h"
#include "estrutura.h"
/**
*@brief 	Funcao que avalia as dependencias
*@param     *linhas ponteiro que aponta para lines
*@param     &countInstruction passarem por referencia de countInstruction
*@return	void
*/
void processando(Comando *linhas, int &countInstruction) {

	
	Dependencia *info = new Dependencia[countInstruction];

	int count = 0;
	int jj = 0;

	while(count < countInstruction) {

		if(linhas[count].informacao[0] == "add") {
			
			if (count > 0) {

				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}
					if(linhas[ii].informacao[1] == linhas[count].informacao[2] || linhas[ii].informacao[1] == linhas[count].informacao[3]) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
										
					} else {
						info[count].instrucao[jj] = -1;
						++jj;
					}
				}
			} else {
				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].informacao[0] == "sub") {
			
			if (count > 0) {

				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}
					if(linhas[ii].informacao[1] == linhas[count].informacao[2] || linhas[ii].informacao[1] == linhas[count].informacao[3]) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
										
					} else {
						info[count].instrucao[jj] = -1;
						++jj;
					}
				}
			} else {
				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].informacao[0] == "j") {
			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].informacao[1].find(linhas[count].informacao[1]);
					std::size_t found2 = linhas[ii].informacao[1].find(linhas[count].informacao[2]);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].informacao[0] == "beq") {
			//count = linhas[count].informacao[3] - 1;

			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].informacao[1].find(linhas[count].informacao[1]);
					std::size_t found2 = linhas[ii].informacao[1].find(linhas[count].informacao[2]);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].informacao[0] == "bne") {
			//count = linhas[count].informacao[3] - 1;

			if (count > 0) {
				
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].informacao[1].find(linhas[count].informacao[1]);
					std::size_t found2 = linhas[ii].informacao[1].find(linhas[count].informacao[2]);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if(linhas[count].informacao[0] == "lw") {

			if (count > 0) {
				string str1, str2;
				int cut1 = 0, cut2 = 0;
				int tamanho1 = linhas[count].informacao[1].size();
				if(tamanho1>3) {
					while(tamanho1-cut1!=4) {
						cut1++;
					}
					str1 = linhas[count].informacao[1].substr(cut1, 3);
				} else {
					str1 = linhas[count].informacao[1];
				}
				int tamanho2 = linhas[count].informacao[2].size();
				if(tamanho2>3) {
					while(tamanho2-cut2!=4) {
						cut2++;
					}
					str2 = linhas[count].informacao[2].substr(cut2, 3);
				} else {
					str2 = linhas[count].informacao[2];
				}
				//cout << "str1: " << str1 << endl;
				//cout << "str2: " << str2 << endl;
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].informacao[1].find(str1);
					std::size_t found2 = linhas[ii].informacao[1].find(str2);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else if (linhas[count].informacao[0] == "sw") {
			if (count > 0) {
				string str1, str2;
				int cut1 = 0, cut2 = 0;
				int tamanho1 = linhas[count].informacao[1].size();
				if(tamanho1>3) {
					while(tamanho1-cut1!=4) {
						cut1++;
					}
					str1 = linhas[count].informacao[1].substr(cut1, 3);
				} else {
					str1 = linhas[count].informacao[1];
				}
				int tamanho2 = linhas[count].informacao[2].size();
				if(tamanho2>3) {
					while(tamanho2-cut2!=4) {
						cut2++;
					}
					str2 = linhas[count].informacao[2].substr(cut2, 3);
				} else {
					str2 = linhas[count].informacao[2];
				}
				//cout << "str1: " << str1 << endl;
				//cout << "str2: " << str2 << endl;
				jj = 0;
				for(int ii=0; ii<count; ii++) {
					if(jj>1) {
						break;
					}

					std::size_t found1 = linhas[ii].informacao[1].find(str1);
					std::size_t found2 = linhas[ii].informacao[1].find(str2);
					if(found1!=std::string::npos) {
						
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}
						
					} else if(found2!=std::string::npos) {
						info[count].instrucao[jj] = ii;
						//cout << ii << endl;
						++jj;
						if(jj > 0 && count == 1) {
							info[count].instrucao[jj] = -1;
						}

					} else {
						info[count].instrucao[jj] = -1;
						++jj;					
					}
					
				}
			} else {

				info[count].instrucao[0] = -1;
				info[count].instrucao[1] = -1;
			}

			++count;
		} else {
			cerr << "Lista de comandos com comando invalido!" << endl;
			exit(1);
		}	
	}

	for(int ii=0; ii<countInstruction; ii++) {
		cout << info[ii].instrucao[0] << "," << info[ii].instrucao[1] << endl;
	}

	//contaCiclos(linhas, info, countInstruction);


	delete[] info;
}
