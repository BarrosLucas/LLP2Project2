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


class GerenteDePersistencia {
public:
	GerenteDePersistencia();

	std::vector<Imovel> recuperarListaImoveis();
	void salvarListaImoveis(std::vector<Imovel> imoveis);

	virtual ~GerenteDePersistencia();
};

#endif /* GERENTEDEPERSISTENCIA_H_ */
