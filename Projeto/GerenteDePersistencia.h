/*
 * GerenteDePersistencia.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef GERENTEDEPERSISTENCIA_H_
#define GERENTEDEPERSISTENCIA_H_

#include "Imovel.h"
#include <vector>
#include <fstream>

#define CASA        0
#define APARTAMENTO 1
#define TERRENO     2

class GerenteDePersistencia {
public:
	GerenteDePersistencia();

	std::vector<Imovel*> recuperarListaImoveis();

	void salvarListaImoveis(std::vector<Imovel*> imoveis);

	virtual ~GerenteDePersistencia();

private:
	std::vector<Imovel*> lerCasas();
	std::vector<Imovel*> lerApartamentos();
	std::vector<Imovel*> lerTerrenos();
};

#endif /* GERENTEDEPERSISTENCIA_H_ */
