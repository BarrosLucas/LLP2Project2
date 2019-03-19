/*
 * Instanceof.cpp
 *
 *  Created on: 18 de mar de 2019
 *      Author: lucas
 */

#include "Instanceof.h"
Instanceof::Instanceof() {
	// TODO Auto-generated constructor stub

}

int Instanceof::instanceof(Imovel *imovel){
	if (dynamic_cast<Casa*>(imovel) != nullptr) {
		return CASA;
	} else if(dynamic_cast<Apartamento*>(imovel) != nullptr) {
		return APARTAMENTO;
	} else if(dynamic_cast<Terreno*>(imovel) != nullptr){
		return TERRENO;
	}
	return -1;
}

Instanceof::~Instanceof() {
	// TODO Auto-generated destructor stub
}

