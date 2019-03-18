/*
 * Apartamento.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "Apartamento.h"


Apartamento::Apartamento(double valor, int tipoOferta, Endereco endereco, std::string posicao, int numQuartos, double valorCondominio, int vagasGaragem, double area, int andar):Imovel(valor, tipoOferta, endereco){
	setPosicao(posicao);
	setNumQuartos(numQuartos);
	setValorCondominio(valorCondominio);
	setVagasGaragem(vagasGaragem);
	setArea(area);
	setAndar(andar);
}

std::string Apartamento::getPosicao(){
	return posicao;
}
void Apartamento::setPosicao(std::string posicao){
	this->posicao = posicao;
}
int Apartamento::getNumQuartos(){
	return numQuartos;
}
void Apartamento::setNumQuartos(int numQuartos){
	this->numQuartos = numQuartos;
}
double Apartamento::getValorCondominio(){
	return valorCondominio;
}
void Apartamento::setValorCondominio(double valorCondominio){
	this->valorCondominio = valorCondominio;
}
int Apartamento::getVagasGaragem(){
	return vagasGararem;
}
void Apartamento::setVagasGaragem(int vagasGaragem){
	this->vagasGararem = vagasGaragem;
}
double Apartamento::getArea(){
	return area;
}
void Apartamento::setArea(double area){
	this->area = area;
}
int Apartamento::getAndar(){
	return andar;
}
void Apartamento::setAndar(int andar){
	this->andar = andar;
}
std::string Apartamento::getDescricao(){
	std::string descricao;
	descricao.append("APARTAMENTO\n");

	descricao.append("Posicao: ");
	descricao.append(getPosicao());
	descricao.append("\n");

	descricao.append("Numero de quartos: ");
	descricao.append(std::to_string(getNumQuartos()));
	descricao.append("\n");

	descricao.append("Valor do Condominio: ");
	descricao.append(std::to_string(getValorCondominio()));
	descricao.append("\n");

	descricao.append("Qnt. de Vagas na Garagem: ");
	descricao.append(std::to_string(getVagasGaragem()));
	descricao.append("\n");

	descricao.append("Area: ");
	descricao.append(std::to_string(getArea()));
	descricao.append("\n");

	descricao.append("Andar: ");
	descricao.append(std::to_string(getAndar()));
	descricao.append("\n");

	descricao.append(Imovel::getDescricao());

	return descricao;
}

/*
   	int tipoOferta;
   	double valor;
	Endereco endereco;
    std::string posicao;
	int numQuartos;
	double valorCondominio;
	int vagasGararem;
	double area;
	int andar;
 * */

std::string Apartamento::toFileType(){
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
	retorno.append("\"posicao\":\"");
	retorno.append(getPosicao());
	retorno.append("\",\n");
	retorno.append("\"numQuartos\":\"");
	retorno.append(std::to_string(getNumQuartos()));
	retorno.append("\",\n");
	retorno.append("\"valorCondominio\":\"");
	retorno.append(std::to_string(getValorCondominio()));
	retorno.append("\",\n");
	retorno.append("\"vagasGaragem\":\"");
	retorno.append(std::to_string(getVagasGaragem()));
	retorno.append("\",\n");
	retorno.append("\"area\":\"");
	retorno.append(std::to_string(getArea()));
	retorno.append("\",\n");
	retorno.append("\"andar\":\"");
	retorno.append(std::to_string(getAndar()));
	retorno.append("\"\n");
	retorno.append("}");

	return retorno;
}

Apartamento::~Apartamento() {
	// TODO Auto-generated destructor stub
}

