/*
 * Terreno.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef TERRENO_H_
#define TERRENO_H_

#include "Imovel.h"

class Terreno : public Imovel{
public:
	Terreno();
	Terreno(double valor, int tipoOferta, Endereco endereco, double area);

	double getArea();
	void setArea(double area);
	std::string getDescricao();

	std::string toFileType();

	virtual ~Terreno();

private:
	double area;
};

#endif /* TERRENO_H_ */
