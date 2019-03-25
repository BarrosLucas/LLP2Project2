/*
 * main.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

#include "Endereco.h"
#include "Terreno.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Instanceof.h"

#include "GerenteDePersistencia.h"
#include "SistemaImobiliaria.h"

using namespace std;

void mostrarDescricoes(std::vector<Imovel*> imoveis);
void mostrarMenuPrincipal(SistemaImobiliaria *sistema);
void pedirTipoDeImovel(int *tipoDeImovel);
void pedirTipoDeOferta(int *tipoDeOferta);
void pedirEndereco(std::string *logradouro, int *numero, std::string *bairro, std::string *cidade, std::string *cep);
Endereco* preencherEndereco(Endereco *endereco);
Endereco* pedirInformacoesCasa(std::string *titulo, double *valor, int *tipoOferta, Endereco *endereco, int *numPavimentos, int *numQuartos, double *areaTerreno, double *areaConstruida);
Endereco* pedirInformacoesApartamento(std::string *titulo, double *valor, int *tipoOferta, Endereco *endereco, std::string *posicao, int *numQuartos, double *valorCondominio, int *vagasGaragem, double *area, int *andar);
Endereco* pedirInformacoesTerreno(std::string * titulo, double * valor, int * tipoOferta, Endereco *endereco, double *area);
bool cadastrarCasa(SistemaImobiliaria *sistema);
bool cadastrarApartamento(SistemaImobiliaria *sistema);
bool cadastrarTerreno(SistemaImobiliaria *sistema);
void listarImoveis(SistemaImobiliaria *sistema);
void incluirFiltro(int * escolha);
bool alterarImovel(SistemaImobiliaria *sistema);
bool removerImovel(SistemaImobiliaria *sistema);

int main(){
	std::vector<Imovel*> todos_imoveis;
	SistemaImobiliaria *sistema = new SistemaImobiliaria();

	todos_imoveis = sistema->getImoveis();

	mostrarMenuPrincipal(sistema);
}

void mostrarMenuPrincipal(SistemaImobiliaria *sistema){
	fflush(stdin);
	char escolha;
	int select;
	cout << "//*****MENU PRINCIPAL*****//" << endl;
	cout << "1 - CADASTRAR IMOVEIS " << endl;
	cout << "2 - LISTAR IMOVEIS " << endl;
	cout << "3 - EDITAR IMOVEIS " << endl;
	cout << "4 - REMOVER IMOVEIS " << endl;
	cout << "OUTRA TECLA - SAIR" << endl;
	cout << "\nESCOLHA: ";
	//escolha = getch();
	cin >> escolha;
	fflush(stdin);
	switch(escolha){
	case '1': //CADASTRAR IMOVEL
	{
		bool resultado = false;
		pedirTipoDeImovel(&select);
		switch(select){
		case 1: //CADASTRAR CASA
		{
			resultado = cadastrarCasa(sistema);
			(resultado)? cout << "CADASTRO REALIZADO COM SUCESSO!" << endl : cout << "FALHA AO EFETUAR O CADASTRO!" << endl;
			Sleep(3000);
			cout << "\n\n\n";
			mostrarMenuPrincipal(sistema);
			break;
		}
		case 2: //CADASTRAR APARTAMENTO
		{
			resultado = cadastrarApartamento(sistema);
			(resultado)? cout << "CADASTRO REALIZADO COM SUCESSO!" << endl : cout << "FALHA AO EFETUAR O CADASTRO!" << endl;
			Sleep(3000);
			cout << "\n\n\n";
			mostrarMenuPrincipal(sistema);
			break;
		}
		case 3: //CADASTRAR TERRENO
		{
			resultado = cadastrarTerreno(sistema);
			(resultado)? cout << "CADASTRO REALIZADO COM SUCESSO!" << endl : cout << "FALHA AO EFETUAR O CADASTRO!" << endl;
			Sleep(3000);
			cout << "\n\n\n";
			mostrarMenuPrincipal(sistema);
			break;
		}
		}
		break;
	}
	case '2': //LISTAR
	{
		listarImoveis(sistema);
		break;
	}
	case '3': //ALTERAR
	{
		if(alterarImovel(sistema)){
			cout << "ATUALIZACAO EFETUADA COM SUCESSO!" << endl;
		}else{
			cout << "ATUALIZACAO NAO PODE SER EFETUADA" << endl;
		}
		Sleep(3000);
		mostrarMenuPrincipal(sistema);
		break;
	}
	case '4': //REMOVER
	{
		if(removerImovel(sistema)){
			cout << "REMOCAO EFETUADA COM SUCESSO!" << endl;
		}else{
			cout << "REMOCAO NAO PODE SER EFETUADA" << endl;
		}
		Sleep(3000);
		mostrarMenuPrincipal(sistema);
		break;
	}
	}
	Sleep(10000);
	mostrarMenuPrincipal(sistema);
}

bool cadastrarTerreno(SistemaImobiliaria *sistema){
	std::string titulo;
	double valor;
	int tipoOferta;
	Endereco *endereco;
	double area;

	endereco = pedirInformacoesTerreno(&titulo,&valor,&tipoOferta,endereco,&area);

	Terreno *terreno = new Terreno(titulo,valor,tipoOferta,*endereco,area);
	sistema ->cadastraImovel(terreno);

	return true;
}

bool cadastrarCasa(SistemaImobiliaria *sistema){
	bool retorno = false;
	std::string titulo;
	double valor;
	int tipoOferta;
	Endereco *endereco;
	int numPavimentos;
	int numQuartos;
	double areaTerreno;
	double areaConstruida;

	endereco = pedirInformacoesCasa(&titulo,&valor,&tipoOferta,endereco,&numPavimentos,&numQuartos,&areaTerreno,&areaConstruida);
	Casa *casa = new Casa(titulo,valor,(tipoOferta-1),*endereco,numPavimentos,numQuartos,areaTerreno,areaConstruida);
	retorno = sistema->cadastraImovel(casa);

	return retorno;
}
bool cadastrarApartamento(SistemaImobiliaria *sistema){
	std::string titulo;
	double valor;
	int tipoOferta;
	Endereco *endereco;
	std::string posicao;
	int numQuartos;
	double valorCondominio;
	int vagasGaragem;
	double area;
	int andar;

	endereco = pedirInformacoesApartamento(&titulo,&valor,&tipoOferta,endereco,&posicao,&numQuartos,&valorCondominio,&vagasGaragem,&area,&andar);
	Apartamento *apartamento = new Apartamento(titulo,valor,tipoOferta,*endereco,posicao,numQuartos,valorCondominio,vagasGaragem,area,andar);

	sistema->cadastraImovel(apartamento);

	return true;
}

Endereco * pedirInformacoesTerreno(std::string * titulo, double * valor, int * tipoOferta, Endereco *endereco, double *area){
	fflush(stdin);

	cout << "\n\nTITULO: ";
	getline(cin,*titulo);

	fflush(stdin);

	cout << "VALOR: R$ ";
	cin >> *valor;

	fflush(stdin);

	pedirTipoDeOferta(tipoOferta);

	fflush(stdin);

	endereco = preencherEndereco(endereco);

	fflush(stdin);

	cout << "AREA: ";
	cin >> *area;

	fflush(stdin);

	return endereco;
}

Endereco* pedirInformacoesApartamento(std::string *titulo, double *valor, int *tipoOferta, Endereco *endereco, std::string *posicao, int *numQuartos, double *valorCondominio, int *vagasGaragem, double *area, int *andar){
	fflush(stdin);

	cout << "\n\nTITULO: ";
	getline(cin,*titulo);

	fflush(stdin);

	cout << "VALOR: R$ ";
	cin >> *valor;

	fflush(stdin);

	pedirTipoDeOferta(tipoOferta);

	fflush(stdin);

	endereco = preencherEndereco(endereco);

	fflush(stdin);

	cout << "POSICAO: ";
	cin >> *posicao;

	fflush(stdin);

	cout << "NUMERO DE QUARTOS: ";
	cin >> *numQuartos;

	fflush(stdin);

	cout << "VALOR DO CONDOMINIO: ";
	cin >> *valorCondominio;

	fflush(stdin);

	cout << "VAGAS NA GARAGEM: ";
	cin >> *vagasGaragem;

	fflush(stdin);

	cout << "AREA: ";
	cin >> *area;

	fflush(stdin);

	cout << "ANDAR: ";
	cin >> *andar;

	fflush(stdin);

	/*cout << "END.: "<<endl;
	cout << endereco->toString() << endl;
	Sleep(5000);*/

	return endereco;
}



Endereco* pedirInformacoesCasa(std::string *titulo, double *valor, int *tipoOferta, Endereco *endereco, int *numPavimentos, int *numQuartos, double *areaTerreno, double *areaConstruida){
	fflush(stdin);
	cout << "\n\nTITULO: ";
	getline(cin,*titulo);
	fflush(stdin);
	cout << "VALOR: R$ ";
	cin >> *valor;
	fflush(stdin);
	pedirTipoDeOferta(tipoOferta);
	fflush(stdin);
	endereco = preencherEndereco(endereco);
	fflush(stdin);
	cout << "NUMERO DE PAVIMENTOS: ";
	cin >> *numPavimentos;
	fflush(stdin);
	cout << "NUMERO DE QUARTOS: ";
	cin >> *numQuartos;
	fflush(stdin);
	cout << "AREA DO TERRENO: ";
	cin >> *areaTerreno;
	fflush(stdin);
	cout << "AREA CONSTRUIDA: ";
	cin >> *areaConstruida;
	fflush(stdin);

	return endereco;
}

Endereco* preencherEndereco(Endereco *endereco){
	std::string logradouro;
	int numero;
	std::string bairro;
	std::string cidade;
	std::string cep;

	pedirEndereco(&logradouro,&numero,&bairro,&cidade,&cep);
	endereco = new Endereco(logradouro,numero,bairro,cidade,cep);

	return endereco;
}

void pedirEndereco(std::string *logradouro, int *numero, std::string *bairro, std::string *cidade, std::string *cep){
	fflush(stdin);
	cout << "\tLOGRADOURO: ";
	getline(cin,*logradouro);
	fflush(stdin);
	cout << "\tNUMERO: ";
	cin >> *numero;
	fflush(stdin);
	cout << "\tBAIRRO: ";
	getline(cin,*bairro);
	fflush(stdin);
	cout << "\tCIDADE: ";
	getline(cin,*cidade);
	fflush(stdin);
	cout << "\tCEP: ";
	getline(cin,*cep);
	fflush(stdin);
}

void pedirTipoDeOferta(int *tipoDeOferta){
	fflush(stdin);
	cout << "TIPO DE OFERTA: " << endl;
	cout << "1 - VENDER" << endl;
	cout << "2 - ALUGAR" << endl;
	cout << "ESCOLHA: ";
	cin >> *tipoDeOferta;
	fflush(stdin);
}

void pedirTipoDeImovel(int *tipoDeImovel){
	fflush(stdin);
	cout << "\n\nTIPO DE IMOVEL: " << endl;
	cout << "1 - CASA" << endl;
	cout << "2 - APARTAMENTO" << endl;
	cout << "3 - TERRENO" << endl;
	cout << "ESCOLHA: ";
	cin >> *tipoDeImovel;
	fflush(stdin);
}

void mostrarDescricoes(std::vector<Imovel*> imoveis){
	Instanceof * instanceof = new Instanceof();
	int cont = 0;
	for(Imovel* imovel : imoveis){
		cout << "- IMOVEL: " << ++cont << endl;
		switch(instanceof->instanceof(imovel)){
		case 0:
		{
			Casa *casa = dynamic_cast<Casa*>(imovel);
			cout << casa->getDescricao() << endl;
			break;
		}
		case 1:
		{
			Apartamento *apartamento = dynamic_cast<Apartamento*>(imovel);
			cout << apartamento->getDescricao() << endl;
			break;
		}
		case 2:{
			Terreno *terreno = dynamic_cast<Terreno*>(imovel);
			cout << terreno->getDescricao() << endl;
			break;
		}
		}
	}
}

void listarImoveis(SistemaImobiliaria *sistema){
	int escolha;
	incluirFiltro(&escolha);
	switch(escolha){
	case 1: //SIM
	{
		int escolhas;
		vector<Imovel*> imoveis = sistema->getImoveis();
		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR PRECO?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);
		if(escolhas == 1){
			fflush(stdin);
			double minPreco,maxPreco;
			cout << "\tPRECO MINIMO (DIGITE 0 SE NAO QUISER INCLUIR O VALOR MINIMO): R$ ";
			cin >> minPreco;
			fflush(stdin);
			cout << "\tPRECO MAXIMO (DIGITE 0 SE NAO QUISER INCLUIR O VALOR MAXIMO): R$ ";
			cin >> maxPreco;
			fflush(stdin);
			imoveis = sistema->getImoveisPorPreco(imoveis,minPreco,maxPreco);
		}
		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR BAIRRO?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);
		if(escolhas == 1){
			string bairro;
			cout << "\tBAIRRO: ";
			getline(cin,bairro);
			fflush(stdin);
			imoveis = sistema->getImoveisPorBairro(imoveis,bairro);
		}
		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR CIDADE?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);
		if(escolhas == 1){
			fflush(stdin);
			string cidade;
			cout << "\tCIDADE: ";
			getline(cin,cidade);
			fflush(stdin);
			imoveis = sistema->getImoveisPorCidade(imoveis,cidade);
		}

		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR TITULO?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);

		if(escolhas == 1){
			fflush(stdin);
			string titulo;
			cout << "\tTITULO: ";
			getline(cin,titulo);
			imoveis = sistema->getImoveisPorTitulo(imoveis,titulo);
			fflush(stdin);
		}

		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR TIPO DE OFERTA?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);

		if(escolhas == 1){
			fflush(stdin);
			int tipo;
			cout << "\t1 - MOSTRAR IMOVEIS PARA VENDER" << endl;
			cout << "\t2 - MOSTRAR IMOVEIS PARA ALUGAR" << endl;
			cout << "ESCOLHA: ";
			cin >> tipo;
			fflush(stdin);
			imoveis = sistema->getImoveisPorCategoria(imoveis,(tipo-1));
		}

		fflush(stdin);
		cout << "\n\nDESEJA FILTRAR POR TIPO DE IMOVEL?" << endl;
		cout << "1 - SIM" << endl;
		cout << "2 - NAO" << endl;
		cout << "ESCOLHA: ";
		cin >> escolhas;
		fflush(stdin);

		if(escolhas == 1){
			fflush(stdin);
			int tipo;
			cout << "\t1 - MOSTRAR CASAS" << endl;
			cout << "\t2 - MOSTRAR APARTAMENTOS" << endl;
			cout << "\t3 - MOSTRAR TERRENOS"<<endl;
			cout << "ESCOLHA: ";
			cin >> tipo;
			fflush(stdin);
			imoveis = sistema->getImoveisPorTipo(imoveis,(tipo-1));
		}
		mostrarDescricoes(imoveis);
		break;
	}
	case 2: //NAO (MOSTRA TODOS)
	{
		mostrarDescricoes(sistema->getImoveis());
		break;
	}
	}
}
void incluirFiltro(int * escolha){
	fflush(stdin);
	cout << "\n\nDESEJA INCLUIR FILTROS?" << endl;
	cout << "1 - SIM" << endl;
	cout << "2 - NAO" << endl;
	cout << "ESCOLHA: ";
	cin >> *escolha;
	fflush(stdin);
}

bool removerImovel(SistemaImobiliaria *sistema){
	//Imovel *imovel;
	bool retorno = false;
	int indice;
	Instanceof *instanceof = new Instanceof();
	vector<Imovel*> imoveis = sistema->getImoveis();

	cout << "\n\nDIGITE O NUMERO DO IMOVEL QUE DESEJA REMOVER: " << endl;
	Sleep(1000);
	mostrarDescricoes(imoveis);
	cout << "\nNUMERO DO IMOVEL: ";
	cin >> indice;
	--indice;

	retorno = sistema->removerImovel(&indice);
	//cout << "OBJETO REMOVIDO!"<<endl;
	//cout << imovel->getDescricao() << endl;
	//Sleep(15000);

	return retorno;
}

bool alterarImovel(SistemaImobiliaria *sistema){
	bool retorno = false;
	int indice;
	Instanceof *instanceof = new Instanceof();
	vector<Imovel*> imoveis = sistema->getImoveis();

	cout << "\n\nDIGITE O NUMERO DO IMOVEL QUE DESEJA ALTERAR... " << endl;
	Sleep(1000);
	mostrarDescricoes(imoveis);
	cout << "\nNUMERO DO IMOVEL: ";
	cin >> indice;

	--indice;

	if(indice > 0 && indice < imoveis.size()){
		if(instanceof->instanceof(imoveis.at(indice))==CASA){
			std::string titulo;
			double valor;
			int tipoOferta;
			Endereco *endereco;
			int numPavimentos;
			int numQuartos;
			double areaTerreno;
			double areaConstruida;

			endereco = pedirInformacoesCasa(&titulo,&valor,&tipoOferta,endereco,&numPavimentos,&numQuartos,&areaTerreno,&areaConstruida);
			Casa *casa = new Casa(titulo,valor,(tipoOferta-1),*endereco,numPavimentos,numQuartos,areaTerreno,areaConstruida);

			retorno = sistema->atualizarImovel(casa,&indice);

		}else if(instanceof->instanceof(imoveis.at(indice))==APARTAMENTO){
			std::string titulo;
			double valor;
			int tipoOferta;
			Endereco *endereco;
			std::string posicao;
			int numQuartos;
			double valorCondominio;
			int vagasGaragem;
			double area;
			int andar;

			endereco = pedirInformacoesApartamento(&titulo,&valor,&tipoOferta,endereco,&posicao,&numQuartos,&valorCondominio,&vagasGaragem,&area,&andar);
			Apartamento *apartamento = new Apartamento(titulo,valor,tipoOferta,*endereco,posicao,numQuartos,valorCondominio,vagasGaragem,area,andar);

			retorno = sistema->atualizarImovel(apartamento,&indice);

		}else if(instanceof->instanceof(imoveis.at(indice))==TERRENO){
			std::string titulo;
			double valor;
			int tipoOferta;
			Endereco *endereco;
			double area;

			endereco = pedirInformacoesTerreno(&titulo,&valor,&tipoOferta,endereco,&area);
			Terreno *terreno = new Terreno(titulo,valor,tipoOferta,*endereco,area);

			retorno = sistema->atualizarImovel(terreno,&indice);
		}else{
			retorno = false;
		}
	}else{
		retorno = false;
	}
	return retorno;

}

