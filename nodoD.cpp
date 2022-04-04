#include "nodoD.h"

nodoD::nodoD()
{
	this->dato = 0;
	this->sgte = NULL;
	this->ante = NULL;
}

nodoD::nodoD(int _dato)
{
	this->dato = _dato;
	this->sgte = NULL;
	this->ante = NULL;
}

int nodoD::getDato()
{
	return this->dato;
}

nodoD* nodoD::getSgte()
{
	return this->sgte;
}

nodoD* nodoD::getAnte()
{
	return this->ante;
}

void nodoD::setDato(int _dato)
{
	this->dato = _dato;
}

void nodoD::setSgte(nodoD* _sgte)
{
	this->sgte = _sgte;
}

void nodoD::setAnte(nodoD* _ante)
{
	this->ante = _ante;
}
