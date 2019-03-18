/*
 * Endereco.h
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#ifndef ENDERECO_H_
#define ENDERECO_H_

#include <string>

class Endereco {
public:
	Endereco();
	Endereco(std::string logradouro, int numero, std::string bairro, std::string cidade, std::string cep);

	std::string getLogradouro();
	void setLogradouro(std::string logradouro);
	int getNumero();
	void setNumero(int numero);
	std::string getBairro();
	void setBairro(std::string bairro);
	std::string getCidade();
	void setCidade(std::string cidade);
	std::string getCep();
	void setCep(std::string cep);
	std::string toString();
	std::string toFileType();

	virtual ~Endereco();

private:
	std::string logradouro;
	int numero;
	std::string bairro;
	std::string cidade;
	std::string cep;
};

#endif /* ENDERECO_H_ */
