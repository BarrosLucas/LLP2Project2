/*
 * Apartamento.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef APARTAMENTO_H_
#define APARTAMENTO_H_

#include <string>
#include "Imovel.h"

class Apartamento : public Imovel{
public:
	Apartamento();
	Apartamento(double valor, int tipoOferta, Endereco endereco, std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, int andar);

	std::string getPosicao();
	void setPosicao(std::string posicao);
	int getNumQuartos();
	void setNumQuartos(int numQuartos);
	double getValorCondominio();
	void setValorCondominio(double valorCondominio);
	int getVagasGaragem();
	void setVagasGaragem(int vagasGaragem);
	double getArea();
	void setArea(double area);
	int getAndar();
	void setAndar(int andar);
	std::string getDescricao();

	std::string toFileType();

	virtual ~Apartamento();

private:
	std::string posicao;
	int numQuartos;
	double valorCondominio;
	int vagasGararem;
	double area;
	int andar;
};

#endif /* APARTAMENTO_H_ */
