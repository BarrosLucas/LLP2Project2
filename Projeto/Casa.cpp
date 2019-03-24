/*
 * Casa.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */

#include "Casa.h"


Casa::Casa() : Imovel(){

}
Casa::Casa(std::string titulo, double valor, int tipoOferta, Endereco endereco, int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida): Imovel(titulo, valor, tipoOferta, endereco){
	setNumPavimentos(numPavimentos);
	setNumQuartos(numQuartos);
	setAreaTerreno(areaTerreno);
	setAreaConstruida(areaConstruida);
}

int Casa::getNumPavimentos(){
	return numPavimentos;
}
void Casa::setNumPavimentos(int numPavimentos){
	this->numPavimentos=numPavimentos;
}
int Casa::getNumQuartos(){
	return numQuartos;
}
void Casa::setNumQuartos(int numQuartos){
	this->numQuartos = numQuartos;
}
double Casa::getAreaTerreno(){
	return areaTerreno;
}
void Casa::setAreaTerreno(double areaTerreno){
	this->areaTerreno = areaTerreno;
}
double Casa::getAreaConstruida(){
	return areaConstruida;
}
void Casa::setAreaConstruida(double areaConstruida){
	this->areaConstruida = areaConstruida;
}
std::string Casa::getDescricao(){
	std::string descricao;
	descricao.append("CASA\n");

	descricao.append("Numero de Pavimentos: ");
	descricao.append(std::to_string(getNumPavimentos()));
	descricao.append("\n");

	descricao.append("Numero de Quarto: ");
	descricao.append(std::to_string(getNumQuartos()));
	descricao.append("\n");

	descricao.append("Area do Terreno: ");
	descricao.append(std::to_string(getAreaTerreno()));
	descricao.append("\n");

	descricao.append("Area Construida: ");
	descricao.append(std::to_string(getAreaConstruida()));
	descricao.append("\n");

	descricao.append(Imovel::getDescricao());

	return descricao;
}
/*
	   	int tipoOferta;
	   	double valor;
		Endereco endereco;
	    int numPavimentos;
		int numQuartos;
		double areaTerreno;
		double areaConstruida;

	 * */
std::string Casa::toFileType(){
	std::string retorno;

	retorno.append("{\n");
	retorno.append("\"titulo\":\"");
	retorno.append(getTitulo());
	retorno.append("\",\n");
	retorno.append("\"tipoOferta\":\"");
	retorno.append(std::to_string(getTipoOferta()));
	retorno.append("\",\n");
	retorno.append("\"valor\":\"");
	retorno.append(std::to_string(getValor()));
	retorno.append("\",\n");
	retorno.append(getEndereco().toFileType());
	retorno.append(",\n");
	retorno.append("\"numPavimentos\":\"");
	retorno.append(std::to_string(getNumPavimentos()));
	retorno.append("\",\n");
	retorno.append("\"numQuartos\":\"");
	retorno.append(std::to_string(getNumQuartos()));
	retorno.append("\",\n");
	retorno.append("\"areaTerreno\":\"");
	retorno.append(std::to_string(getAreaTerreno()));
	retorno.append("\",\n");
	retorno.append("\"areaConstruida\":\"");
	retorno.append(std::to_string(getAreaConstruida()));
	retorno.append("\"\n");
	retorno.append("}");

	return retorno;


}

Casa::~Casa() {
	// TODO Auto-generated destructor stub
}

