/*
 * main.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */
#include <fstream>
#include <iostream>

#include "Endereco.h"
#include "Terreno.h"
#include "Casa.h"
#include "Apartamento.h"

using namespace std;

int main(){
	string teste;
	ofstream arquivo;
	arquivo.open("persistencia/teste.txt");


	Endereco *endereco = new Endereco("Rua 1", 1, "Bairro 1", "Cidade 1", "11111-111");


	Terreno *terreno = new Terreno(150.5, 0, *endereco, 13.4);
	Casa *casa = new Casa(20.3, 1, *endereco, 3, 1, 4, 5);
	Apartamento *apartamento = new Apartamento(14.7, 1, *endereco, "Aqui", 2, 13, 5, 110, 3);

	arquivo << terreno->toFileType() << endl;
	arquivo << casa->toFileType() << endl;
	arquivo << apartamento->toFileType() << endl;

}
