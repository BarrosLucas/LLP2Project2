/*
 * main.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */
#include <fstream>
#include <iostream>
#include <vector>

#include "Endereco.h"
#include "Terreno.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Instanceof.h"

#include "GerenteDePersistencia.h"

using namespace std;

int main(){
	std::vector<Imovel*> imoveis;

	GerenteDePersistencia * adm = new GerenteDePersistencia();
	Instanceof * instanceof = new Instanceof();

	imoveis = adm->recuperarListaImoveis();


	for(Imovel* imovel : imoveis){
		switch(instanceof->instanceof(imovel)){
		case 0:
		{
			Casa *casa = dynamic_cast<Casa*>(imovel);
			cout << casa->getDescricao() << endl;
			break;
		}
		case 1:
			{
				Apartamento *apartamento = dynamic_cast<Apartamento*>(imovel);
				cout << apartamento->getDescricao() << endl;
				break;
			}
		case 2:{
			Terreno *terreno = dynamic_cast<Terreno*>(imovel);
			cout << terreno->getDescricao() << endl;
			break;
		}
		}
	}

}
