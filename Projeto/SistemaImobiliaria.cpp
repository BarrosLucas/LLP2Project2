/*
 * SistemaImobiliaria.cpp
 *
 *  Created on: 9 de mar de 2019
 *      Author: lucas
 */
#include "SistemaImobiliaria.h"
#include "Instanceof.h"
#include <locale>
#include <iostream>
#include "ManipuladorString.h"
#include "GerenteDePersistencia.h"

#define CASA        0
#define APARTAMENTO 1
#define TERRENO     2

//#define

SistemaImobiliaria::SistemaImobiliaria() {
	// TODO Auto-generated constructor stub
	GerenteDePersistencia * adm = new GerenteDePersistencia();
	this->imoveis = adm->recuperarListaImoveis();
}

bool SistemaImobiliaria::cadastraImovel(Imovel *imovel){
	if(imovel->getEndereco().getBairro().length()>0 &&
			imovel->getEndereco().getCep().length()==9 &&
			imovel->getEndereco().getCidade().length()>0 &&
			imovel->getEndereco().getLogradouro().length()>0 &&
			imovel->getEndereco().getNumero()>0){
		Instanceof *instanceof = new Instanceof();
		if(instanceof->instanceof(imovel)==CASA){
			Casa *casa = dynamic_cast<Casa*>(imovel);
			if(casa->getAreaConstruida()>0 && casa->getAreaTerreno()>0 && casa->getDescricao().length()>0 && casa->getNumPavimentos()>=0 && casa->getNumQuartos()>0 && (casa->getTipoOferta() == 0 || casa->getTipoOferta() == 1) && casa->getValor()>0){
				imoveis.push_back(casa);
				return true;
			}
			return false;
		}else if(instanceof->instanceof(imovel)==APARTAMENTO){
			Apartamento *apartamento = dynamic_cast<Apartamento*>(imovel);
			if(apartamento->getAndar()>=0 && apartamento->getArea()>0 && apartamento->getDescricao().length()>0 && apartamento->getNumQuartos()>0 && apartamento->getPosicao().length()>0 && (apartamento->getTipoOferta()==0 || apartamento->getTipoOferta()==1) && apartamento->getVagasGaragem()>=0 && apartamento->getValor()>0 && apartamento->getValorCondominio()>=0) {
				imoveis.push_back(apartamento);
				return true;
			}
			return false;
		}else if(instanceof->instanceof(imovel)==TERRENO){
			Terreno *terreno = dynamic_cast<Terreno*>(imovel);
			if(terreno->getArea()>0 && terreno->getDescricao().length()>0 && (terreno->getTipoOferta()==0 || terreno->getTipoOferta()==1) && terreno->getValor()>0) {
				imoveis.push_back(terreno);
				return true;
			}
			return false;
		}
	}
	return false;
}
std::vector<Imovel*> SistemaImobiliaria::getImoveis(){
	return imoveis;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisPorTipo(std::vector<Imovel*> imoveis, int tipo){
	std::vector<Imovel*> retorno;
	Instanceof *instanceof = new Instanceof();
	for(Imovel *imovel : imoveis){
		if(instanceof->instanceof(imovel)==tipo){
			retorno.push_back(imovel);
		}
	}

	return retorno;
}
std::vector<Imovel*> SistemaImobiliaria::getImoveisPorCategoria(std::vector<Imovel*> imoveis, int categoria){
	std::vector<Imovel*> retorno;

	for(Imovel *imovel : imoveis){
		if(imovel->getTipoOferta()==categoria){
			retorno.push_back(imovel);
		}
	}

	return retorno;
}
std::vector<Imovel*> SistemaImobiliaria::getImoveisPorBairro(std::vector<Imovel*> imoveis, std::string bairro){
	std::vector<Imovel*> retorno;
	for(Imovel *imovel : imoveis){
		if(imovel->getEndereco().getBairro()==bairro){
			retorno.push_back(imovel);
		}
	}
	return retorno;
}
std::vector<Imovel*> SistemaImobiliaria::getImoveisPorCidade(std::vector<Imovel*> imoveis, std::string cidade){
	std::vector<Imovel*> retorno;
	for(Imovel *imovel : imoveis){
		if(imovel->getEndereco().getCidade()==cidade){
			retorno.push_back(imovel);
		}
	}

	return retorno;
}

std::vector<Imovel*> SistemaImobiliaria::getImoveisPorPreco(std::vector<Imovel*> imoveis, double minValue, double maxValue){
	std::vector<Imovel*> retorno;
	for(Imovel *imovel : imoveis){
		if(minValue == 0 && maxValue != 0){
			if(imovel->getValor()<=maxValue){
				retorno.push_back(imovel);
			}
		}else if(minValue != 0 && maxValue == 0){
			if(imovel->getValor()>=minValue){
				retorno.push_back(imovel);
			}
		}else{
			if(imovel->getValor()>=minValue && imovel->getValor()<=maxValue){
				retorno.push_back(imovel);
			}
		}

	}
	return retorno;

}
std::vector<Imovel*> SistemaImobiliaria::getImoveisPorTitulo(std::vector<Imovel*> imoveis, std::string titulo){
	std::vector<Imovel*> retorno;
	for(Imovel *imovel : imoveis){
		if(imovel->getTitulo()==titulo){
			retorno.push_back(imovel);
		}
	}

	return retorno;

}
bool SistemaImobiliaria::atualizarImovel(Imovel *imovel,int *index){
	if(*index > 0 && *index < imoveis.size()){
		if(imovel->getEndereco().getBairro().length()>0 &&
				imovel->getEndereco().getCep().length()==9 &&
				imovel->getEndereco().getCidade().length()>0 &&
				imovel->getEndereco().getLogradouro().length()>0 &&
				imovel->getEndereco().getNumero()>0){
			Instanceof *instanceof = new Instanceof();
			if(instanceof->instanceof(imovel)==CASA){
				Casa *casa = dynamic_cast<Casa*>(imovel);
				if(casa->getAreaConstruida()>0 && casa->getAreaTerreno()>0 && casa->getDescricao().length()>0 && casa->getNumPavimentos()>=0 && casa->getNumQuartos()>0 && (casa->getTipoOferta() == 0 || casa->getTipoOferta() == 1) && casa->getValor()>0){
					imoveis[*index] = imovel;
					return true;
				}
				return false;
			}else if(instanceof->instanceof(imovel)==APARTAMENTO){
				Apartamento *apartamento = dynamic_cast<Apartamento*>(imovel);
				if(apartamento->getAndar()>=0 && apartamento->getArea()>0 && apartamento->getDescricao().length()>0 && apartamento->getNumQuartos()>0 && apartamento->getPosicao().length()>0 && (apartamento->getTipoOferta()==0 || apartamento->getTipoOferta()==1) && apartamento->getVagasGaragem()>=0 && apartamento->getValor()>0 && apartamento->getValorCondominio()>=0) {
					imoveis[*index] = imovel;
					return true;
				}
				return false;
			}else if(instanceof->instanceof(imovel)==TERRENO){
				Terreno *terreno = dynamic_cast<Terreno*>(imovel);
				if(terreno->getArea()>0 && terreno->getDescricao().length()>0 && (terreno->getTipoOferta()==0 || terreno->getTipoOferta()==1) && terreno->getValor()>0) {
					imoveis[*index] = imovel;
					return true;
				}
				return false;
			}
		}
		return false;
	}
	return false;
}
bool SistemaImobiliaria::removerImovel(int *index){
	if(*index > 0 && *index < imoveis.size()){
		imoveis.erase(imoveis.begin()+*index);
		return true;
	}
	return false;
}

SistemaImobiliaria::~SistemaImobiliaria() {
	// TODO Auto-generated destructor stub
}

