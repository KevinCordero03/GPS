#include "nodoS.h"

nodoS::nodoS()
{
	this->dato = 0;
	this->sgte = NULL;
}

nodoS::nodoS(int _dato)
{
	this->dato = _dato;
	this->sgte = NULL;
	
}

int nodoS::getDato()
{
	return this->dato;
}

nodoS* nodoS::getSgte()
{

	return this->sgte;
}

void nodoS::setDato(int _dato)
{
	this->dato = _dato;
}

void nodoS::setSgte(nodoS* _sgte)
{
	this->sgte = _sgte;
}
