/*
 * SistemaImobiliaria.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef SISTEMAIMOBILIARIA_H_
#define SISTEMAIMOBILIARIA_H_

#define IMOVEL_PARA_VENDER 0
#define IMOVEL_PARA_ALUGAR 1

#include <vector>
#include "Imovel.h"

class SistemaImobiliaria {
public:
	SistemaImobiliaria();

	bool cadastraImovel(Imovel imovel);
	std::vector<Imovel*> getImoveis();
	std::vector<std::string> getDescricaoImoveis();
	std::vector<Imovel*> getImoveisPorTipo(std::vector<Imovel*> imoveis, int tipo);
	std::vector<Imovel*> getImoveisPorCategoria(std::vector<Imovel*> imoveis, int categoria);
	std::vector<Imovel*> getImoveisPorBairro(std::vector<Imovel*> imoveis, std::string bairro);
	std::vector<Imovel*> getImoveisPorCidade(std::vector<Imovel*> imoveis, std::string cidade);
	std::vector<Imovel*> getImoveisPorPreco(std::vector<Imovel*> imoveis, double minValue, double maxValue);
	std::vector<Imovel*> getImoveisPorTitulo(std::vector<Imovel*> imoveis, std::string titulo);


	virtual ~SistemaImobiliaria();

private:
	std::vector<Imovel*> imoveis;
};

#endif /* SISTEMAIMOBILIARIA_H_ */
