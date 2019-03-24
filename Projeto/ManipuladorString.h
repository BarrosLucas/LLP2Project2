/*
 * ManipuladorString.h
 *
 *  Created on: 20 de mar de 2019
 *      Author: lucas
 */

#ifndef MANIPULADORSTRING_H_
#define MANIPULADORSTRING_H_

#include <string>
#include <locale>

class ManipuladorString {
public:
	ManipuladorString();

	bool stringsCombinam(std::string string1, std::string string2);
	char temAcento(std::string caractere);
	std::string retirarAcento(std::string texto);

	virtual ~ManipuladorString();
};

#endif /* MANIPULADORSTRING_H_ */
