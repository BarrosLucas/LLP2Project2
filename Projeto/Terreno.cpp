/*
 * Terreno.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "Terreno.h"

Terreno::Terreno(double valor, int tipoOferta, Endereco endereco, double area) : Imovel(valor, tipoOferta, endereco){
	setArea(area);
}

double Terreno::getArea(){
	return area;
}
void Terreno::setArea(double area){
	this->area = area;
}

std::string Terreno::getDescricao(){
	std::string descricao;
	descricao.append("TERRENO\n");
	descricao.append("Area: ");
	descricao.append(std::to_string(getArea()));
	descricao.append("\n");
	descricao.append(Imovel::getDescricao());

	return descricao;
}


std::string Terreno::toFileType(){
	std::string retorno;

	retorno.append("{\n");
	retorno.append("\"tipoOferta\":\"");
	retorno.append(std::to_string(getTipoOferta()));
	retorno.append("\",\n");
	retorno.append("\"valor\":\"");
	retorno.append(std::to_string(getValor()));
	retorno.append("\",\n");
	retorno.append(getEndereco().toFileType());
	retorno.append(",\n");
	retorno.append("\"area\":\"");
	retorno.append(std::to_string(getArea()));
	retorno.append("\"\n");
	retorno.append("}");

	return retorno;
}


Terreno::~Terreno() {
	// TODO Auto-generated destructor stub
}

