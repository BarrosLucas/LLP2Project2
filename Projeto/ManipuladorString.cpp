/*
 * ManipuladorString.cpp
 *
 *  Created on: 20 de mar de 2019
 *      Author: lucas
 */
#include <iostream>
#include "ManipuladorString.h"
#include <locale>

ManipuladorString::ManipuladorString() {
	// TODO Auto-generated constructor stub

}

bool ManipuladorString::stringsCombinam(std::string string1, std::string string2){
	string1 = deixarMaisculo(string1);
	string2 = deixarMaisculo(string2);

//	std::cout << string1.substr(0,string1.length()) << " == " << string2.substr(0,string1.length()) << (string1.substr(0,string1.length())==string2.substr(0,string1.length())) << std::endl;

	if(string1.length()<=string2.length()){
		if(string1.substr(0,string1.length())==string2.substr(0,string1.length())){
			return true;
		}
		return false;
	}/*else{
		if(string1.substr(0,string2.length())==string2.substr(0,string2.length())){
			return true;
		}
		return false;
	}*/
	return false;
}

std::string ManipuladorString::retirarAcento(std::string texto){
	std::string retorno;
	int i;
	for(i = 0; i < texto.length();i++){
		std::cout << "i: " << i << "\t trecho: " << texto.substr(i,i+1);
		if(temAcento(texto.substr(i,i+1))!=-1){
			std::cout << "\tif\t";
			retorno += temAcento(texto.substr(i,i+1));
			i+=1;
		}else{
			std::cout << "\telse\t";
			retorno += std::toupper(texto[i]);
		}
		std::cout << " retorno: " << retorno << std::endl;

	}
	std::cout << "Sem acento: " << retorno << std::endl;
	return retorno;
}
std::string ManipuladorString::deixarMaisculo(std::string texto){
	std::string retorno;
	int i;
	for(i=0;i<texto.length();i++){
		retorno += std::toupper(texto[i]);
	}
	return retorno;
}

char ManipuladorString::temAcento(std::string caractere){

	if(caractere == "À" ||
			caractere == "à" ||

			caractere == "Â" ||
			caractere == "â" ||

			caractere == "Á" ||
			caractere == "á" ||

			caractere == "Ä" ||
			caractere == "ä" ||

			caractere == "Ã" ||
			caractere == "ã" ||

			caractere == "Å" ||
			caractere == "å"){
		return 'A';
	}else if(caractere == "Ç" ||
			caractere == "ç"){
		////std::cout << "Caractere retornado: C" << std::endl;
		return 'C';
	}else if(caractere == "Ê" ||
			caractere == "ê"  ||

			caractere ==  "È" ||
			caractere == "è"  ||

			caractere == "Ë" ||
			caractere == "ë" ||

			caractere == "É" ||
			caractere == "é"){
		////std::cout << "Caractere retornado: E" << std::endl;
		return 'E';
	}else if(caractere == "Í" ||
			caractere == "í" ||

			caractere == "Î" ||
			caractere == "î" ||

			caractere == "Ï" ||
			caractere == "ï" ||

			caractere == "Ì" ||
			caractere == "ì"){
		////std::cout << "Caractere retornado: I" << std::endl;
		return 'I';
	}else if(caractere == "Ñ" ||
			caractere == "ñ"){
		//std::cout << "Caractere retornado: N" << std::endl;
		return 'N';
	}else if(caractere == "Ô" ||
			caractere == "ô" ||

			caractere == "Ò" ||
			caractere == "ò" ||

			caractere == "Õ" ||
			caractere == "õ" ||

			caractere == "Ó" ||
			caractere == "ó" ||

			caractere == "Ö" ||
			caractere == "ö"){
		//std::cout << "Caractere retornado: O" << std::endl;
		return 'O';
	}else if(caractere == "Ü" ||
			caractere == "ü" ||

			caractere == "Ú" ||
			caractere == "ú" ||

			caractere == "Û" ||
			caractere == "û" ||

			caractere == "Ù" ||
			caractere == "ù"){
		//std::cout << "Caractere retornado: U" << std::endl;
		return 'U';
	}else if(caractere == "Ý" ||
			caractere == "ý"){
		//std::cout << "Caractere retornado: Y" << std::endl;
		return 'Y';
	}
	//std::cout << "Caractere retornado: "<< caractere[0] << std::endl;
	return -1;

}

ManipuladorString::~ManipuladorString() {
	// TODO Auto-generated destructor stub
}

