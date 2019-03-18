/*
 * SistemaImobiliaria.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef SISTEMAIMOBILIARIA_H_
#define SISTEMAIMOBILIARIA_H_

#include <vector>
#include "Imovel.h"

class SistemaImobiliaria {
public:
	SistemaImobiliaria();

	/*void cadastraImovel(Imovel imovel);
	std::vector<Imovel> getImoveis();
	std::vector<std::string> getDescricaoImoveis();
	std::vector<Imovel> getImoveisPorTipo(int tipo);
	std::vector<Imovel> getImoveisParaAlugarPorBairro(std::string bairro);
	std::vector<Imovel> getImoveisParaVenderPorBairro(std::string bairro);
	std::vector<Imovel> getImoveisPorCidade(std::string cidade);
*/
	virtual ~SistemaImobiliaria();

private:
	std::vector<Imovel> imoveis;
};

#endif /* SISTEMAIMOBILIARIA_H_ */
