/*
 * GerenteDePersistencia.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "GerenteDePersistencia.h"
#include "Imovel.h"
#include "Casa.h"
#include "Instanceof.h"
#include <fstream>
#include <iostream>

GerenteDePersistencia::GerenteDePersistencia() {
	// TODO Auto-generated constructor stub
}

std::vector<Imovel*> GerenteDePersistencia::recuperarListaImoveis(){
	std::vector<Imovel*> retorno;
	for(Imovel* imovel: lerCasas()){
		retorno.push_back(imovel);
	}
	for(Imovel* imovel: lerApartamentos()){
		retorno.push_back(imovel);
	}
	for(Imovel* imovel: lerTerrenos()){
		retorno.push_back(imovel);
	}
	return retorno;
}

std::vector<Imovel*> GerenteDePersistencia::lerCasas(){
	std::vector<Imovel*> retorno;

	std::string linha;
	std::ifstream arqCasa("persistencia/casa.txt");

	Casa *casa = new Casa();
	Endereco *end = new Endereco();

	int contChaves = 0;
	int contAspas = 0;
	bool command = false;
	std::string comando;
	std::string valor;
	if(arqCasa.is_open()){
		while(getline(arqCasa,linha)){
			for(int i = 0; i < linha.length();i++){
				//std::cout << "Comando: " << comando << std::endl;
				//std::cout << "Valor: " << valor << std::endl;
				if(contAspas == 0){
					if(linha[i]=='{'){
						contChaves ++;
						command = true;
						comando = "";
						valor = "";
					}else if(linha[i] == '}'){
						contChaves --;
						if(contChaves == 0){
							casa->setEndereco(*end);
							retorno.push_back(&(*casa));
							casa = new Casa();
							end = new Endereco();
						}
					}else if(linha[i] == '"'){
						contAspas ++;
					}
				}else{
					if(linha[i] == '"'){
						contAspas --;
						if(!command){
							if(comando == "tipoOferta"){
								casa->setTipoOferta(std::stoi(valor));
							}else if(comando == "valor"){
								casa->setValor(std::stod(valor));
							}else if(comando == "numPavimentos"){
								casa->setNumPavimentos(std::stoi(valor));
							}else if(comando == "numQuartos"){
								casa->setNumQuartos(std::stoi(valor));
							}else if(comando == "areaTerreno"){
								casa->setAreaTerreno(std::stod(valor));
							}else if(comando == "areaConstruida"){
								casa->setAreaConstruida(std::stod(valor));
							}else if(comando == "logradouro"){
								end->setLogradouro(valor);
							}else if(comando == "numero"){
								end->setNumero(std::stoi(valor));
							}else if(comando == "bairro"){
								end->setBairro(valor);
							}else if(comando == "cidade"){
								end->setCidade(valor);
							}else if(comando == "cep"){
								end->setCep(valor);
							}else if(comando == "titulo"){
								casa->setTitulo(valor);
							}
							comando = "";
							valor = "";
						}
						command = !command;
					}else if(command && i != linha.length()){
						comando += linha[i];
					}else if(!command && i != linha.length()){
						valor += linha[i];
					}
				}
			}
		}
	}


	return retorno;
}
std::vector<Imovel*> GerenteDePersistencia::lerApartamentos(){
	std::vector<Imovel*> retorno;

	std::string linha;
	std::ifstream arqApartamento("persistencia/apartamento.txt");

	Apartamento *apartamento = new Apartamento();
	Endereco *end = new Endereco();

	int contChaves = 0;
	int contAspas = 0;
	bool command = false;
	std::string comando;
	std::string valor;
	if(arqApartamento.is_open()){
		while(getline(arqApartamento,linha)){
			for(int i = 0; i < linha.length();i++){
				//std::cout << "Comando: " << comando << std::endl;
				//std::cout << "Valor: " << valor << std::endl;
				if(contAspas == 0){
					if(linha[i]=='{'){
						contChaves ++;
						command = true;
						comando = "";
						valor = "";
					}else if(linha[i] == '}'){
						contChaves --;
						if(contChaves == 0){
							apartamento->setEndereco(*end);
							retorno.push_back(&(*apartamento));
							apartamento = new Apartamento();
							end = new Endereco();
						}
					}else if(linha[i] == '"'){
						contAspas ++;
					}
				}else{
					if(linha[i] == '"'){
						contAspas --;
						if(!command){
							if(comando == "tipoOferta"){
								apartamento->setTipoOferta(std::stoi(valor));
							}else if(comando == "valor"){
								apartamento->setValor(std::stod(valor));
							}else if(comando == "posicao"){
								apartamento->setPosicao(valor);
							}else if(comando == "numQuartos"){
								apartamento->setNumQuartos(std::stoi(valor));
							}else if(comando == "valorCondominio"){
								apartamento->setValorCondominio(std::stod(valor));
							}else if(comando == "vagasGaragem"){
								apartamento->setVagasGaragem(std::stoi(valor));
							}else if(comando == "area"){
								apartamento->setArea(std::stod(valor));
							}else if(comando == "andar"){
								apartamento->setAndar(std::stoi(valor));
							}else if(comando == "logradouro"){
								end->setLogradouro(valor);
							}else if(comando == "numero"){
								end->setNumero(std::stoi(valor));
							}else if(comando == "bairro"){
								end->setBairro(valor);
							}else if(comando == "cidade"){
								end->setCidade(valor);
							}else if(comando == "cep"){
								end->setCep(valor);
							}else if(comando == "titulo"){
								apartamento->setTitulo(valor);
							}
							comando = "";
							valor = "";
						}
						command = !command;
					}else if(command && i != linha.length()){
						comando += linha[i];
					}else if(!command && i != linha.length()){
						valor += linha[i];
					}
				}
			}
		}
	}


	return retorno;
}
std::vector<Imovel*> GerenteDePersistencia::lerTerrenos(){
	std::vector<Imovel*> retorno;

	std::string linha;
	std::ifstream arqTerreno("persistencia/terreno.txt");

	Terreno *terreno = new Terreno();
	Endereco *end = new Endereco();

	int contChaves = 0;
	int contAspas = 0;
	bool command = false;
	std::string comando;
	std::string valor;
	if(arqTerreno.is_open()){
		while(getline(arqTerreno,linha)){
			for(int i = 0; i < linha.length();i++){
				//std::cout << "Comando: " << comando << std::endl;
				//std::cout << "Valor: " << valor << std::endl;
				if(contAspas == 0){
					if(linha[i]=='{'){
						contChaves ++;
						command = true;
						comando = "";
						valor = "";
					}else if(linha[i] == '}'){
						contChaves --;
						if(contChaves == 0){
							terreno->setEndereco(*end);
							retorno.push_back(&(*terreno));
							terreno = new Terreno();
							end = new Endereco();
						}
					}else if(linha[i] == '"'){
						contAspas ++;
					}
				}else{
					if(linha[i] == '"'){
						contAspas --;
						if(!command){
							if(comando == "tipoOferta"){
								terreno->setTipoOferta(std::stoi(valor));
							}else if(comando == "valor"){
								terreno->setValor(std::stod(valor));
							}else if(comando == "area"){
								terreno->setArea(std::stod(valor));
							}else if(comando == "logradouro"){
								end->setLogradouro(valor);
							}else if(comando == "numero"){
								end->setNumero(std::stoi(valor));
							}else if(comando == "bairro"){
								end->setBairro(valor);
							}else if(comando == "cidade"){
								end->setCidade(valor);
							}else if(comando == "cep"){
								end->setCep(valor);
							}else if(comando == "titulo"){
								terreno->setTitulo(valor);
							}
							comando = "";
							valor = "";
						}
						command = !command;
					}else if(command && i != linha.length()){
						comando += linha[i];
					}else if(!command && i != linha.length()){
						valor += linha[i];
					}
				}
			}
		}
	}


	return retorno;

}

void GerenteDePersistencia::salvarListaImoveis(std::vector<Imovel*> imoveis){
	std::ofstream arqCasa;
	std::ofstream arqApto;
	std::ofstream arqTerr;

	arqCasa.open("persistencia/casa.txt");
	arqApto.open("persistencia/apartamento.txt");
	arqTerr.open("persistencia/terreno.txt");

	Instanceof *instanceof = new Instanceof();

	int i = 0;;
	for(std::vector<Imovel*>::iterator it = (imoveis).begin();it < (imoveis).end();it++,i++){

		Imovel *imovel = imoveis.at(i);

		switch(instanceof->instanceof(imovel)){
		case CASA:
			{
				Casa *casa = dynamic_cast<Casa*>(imovel);
				arqCasa << casa->toFileType() << std::endl;
				break;
			}
		case APARTAMENTO:
		{
			Apartamento *apartamento = dynamic_cast<Apartamento*>(imovel);
			arqApto << apartamento->toFileType() << std::endl;
			break;
		}
		case TERRENO:
		{
			Terreno *terreno = dynamic_cast<Terreno*>(imovel);
			arqTerr << terreno->toFileType() << std::endl;
			break;
		}
		}
	}
}

GerenteDePersistencia::~GerenteDePersistencia() {
	// TODO Auto-generated destructor stub
}

