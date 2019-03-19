/*
 * Instanceof.h
 *
 *  Created on: 18 de mar de 2019
 *      Author: lucas
 */

#ifndef INSTANCEOF_H_
#define INSTANCEOF_H_

#define CASA        0
#define APARTAMENTO 1
#define TERRENO     2


#include "Imovel.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Terreno.h"

class Instanceof {
public:
	Instanceof();

	int instanceof(Imovel *imovel);

	virtual ~Instanceof();
};

#endif /* INSTANCEOF_H_ */
