/*
 * Imovel.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef IMOVEL_H_
#define IMOVEL_H_

#define IMOVEL_PARA_VENDER 0
#define IMOVEL_PARA_ALUGAR 1

#include "Endereco.h"

class Imovel {
public:
	Imovel(double valor, int tipoOferta, Endereco endereco);

	double getValor();
	void setValor(double valor);
	int getTipoOferta();
	void setTipoOferta(int tipoOferta);
	Endereco getEndereco();
	void setEndereco(Endereco endereco);
	std::string getDescricao();

	virtual std::string toFileType()=0;


	virtual ~Imovel();

private:
	double valor;
	int tipoOferta;
	Endereco endereco;
};

#endif /* IMOVEL_H_ */
