/*
 * Imovel.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "Imovel.h"

Imovel::Imovel(){

}
Imovel::Imovel(std::string titulo, double valor, int tipoOferta, Endereco endereco){
	setValor(valor);
	setTipoOferta(tipoOferta);
	setEndereco(endereco);
	setTitulo(titulo);
}

std::string Imovel::getTitulo(){
	return titulo;
}

void Imovel::setTitulo(std::string titulo){
	this->titulo = titulo;
}

double Imovel::getValor(){
	return valor;
}
void Imovel::setValor(double valor){
	this->valor = valor;
}
int Imovel::getTipoOferta(){
	return tipoOferta;
}
void Imovel::setTipoOferta(int tipoOferta){
	this->tipoOferta = tipoOferta;
}
Endereco Imovel::getEndereco(){
	return endereco;
}
void Imovel::setEndereco(Endereco endereco){
	this->endereco = endereco;
}
std::string Imovel::getDescricao(){
	std::string descricao;
	descricao.append("Título: ");
	descricao.append(getTitulo());
	descricao.append("\n");
	descricao.append("Tipo de Oferta: ");
	descricao.append((getTipoOferta()==IMOVEL_PARA_ALUGAR)? "ALUGAR\n" : "VENDER\n");
	descricao.append("Valor: R$ ");
	descricao.append(std::to_string(getValor()));
	descricao.append("\n");
	descricao.append(endereco.toString());

	return descricao;
}

Imovel::~Imovel() {
	// TODO Auto-generated destructor stub
}

