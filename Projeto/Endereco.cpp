/*
 * Endereco.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "Endereco.h"

Endereco::Endereco(){
}
Endereco::Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep){
	setLogradouro(logradouro);
	setNumero(numero);
	setBairro(bairro);
	setCidade(cidade);
	setCep(cep);
}

std::string Endereco::getLogradouro(){
	return logradouro;
}
void Endereco::setLogradouro(std::string logradouro){
	this->logradouro = logradouro;
}
int Endereco::getNumero(){
	return numero;
}
void Endereco::setNumero(int numero){
	this->numero = numero;
}
std::string Endereco::getBairro(){
	return bairro;
}
void Endereco::setBairro(std::string bairro){
	this->bairro = bairro;
}
std::string Endereco::getCidade(){
	return cidade;
}
void Endereco::setCidade(std::string cidade){
	this->cidade = cidade;
}
std::string Endereco::getCep(){
	return cep;
}
void Endereco::setCep(std::string cep){
	this->cep = cep;
}
std::string Endereco::toString(){
	std::string retorno;
	retorno.append("Endereco: ");

	retorno.append("\n\tLogradouro: ");
	retorno.append(getLogradouro());
	retorno.append("\n");

	retorno.append("\tNumero: ");
	retorno.append(std::to_string(getNumero()));
	retorno.append("\n");

	retorno.append("\tBairro: ");
	retorno.append(getBairro());
	retorno.append("\n");

	retorno.append("\tCidade: ");
	retorno.append(getCidade());
	retorno.append("\n");

	retorno.append("\tCEP: ");
	retorno.append(getCep());
	retorno.append("\n");

	return retorno;
}

std::string Endereco::toFileType(){
	std::string retorno;

	retorno.append("\"endereco\":");
	retorno.append("\n{\n");

	retorno.append("\"logradouro\":\"");
	retorno.append(this->getLogradouro());
	retorno.append("\",\n");

	retorno.append("\"numero\":\"");
	retorno.append(std::to_string(this->getNumero()));
	retorno.append("\",\n");

	retorno.append("\"bairro\":\"");
	retorno.append(this->getBairro());
	retorno.append("\",\n");

	retorno.append("\"cidade\":\"");
	retorno.append(this->getCidade());
	retorno.append("\",\n");

	retorno.append("\"cep\":\"");
	retorno.append(this->getCep());
	retorno.append("\"\n");

	retorno.append("}");

	return retorno;
}


Endereco::~Endereco() {
	// TODO Auto-generated destructor stub
}

