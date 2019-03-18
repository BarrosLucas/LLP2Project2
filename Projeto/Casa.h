/*
 * Casa.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef CASA_H_
#define CASA_H_

#include "Imovel.h"

class Casa : public Imovel{
public:
	Casa(double valor, int tipoOferta, Endereco endereco, int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida);

	int getNumPavimentos();
	void setNumPavimentos(int numPavimentos);
	int getNumQuartos();
	void setNumQuartos(int numQuartos);
	double getAreaTerreno();
	void setAreaTerreno(double areaTerreno);
	double getAreaConstruida();
	void setAreaConstruida(double areaConstruida);
	std::string getDescricao();

	std::string toFileType();

	virtual ~Casa();

private:
	int numPavimentos;
	int numQuartos;
	double areaTerreno;
	double areaConstruida;
};

#endif /* CASA_H_ */
