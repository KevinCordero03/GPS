#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class nodoD
{
private:
	int dato;
	nodoD* sgte;
	nodoD* ante;

public:
	nodoD();
	nodoD(int);

	int getDato();
	nodoD* getSgte();
	nodoD* getAnte();

	void setDato(int);
	void setSgte(nodoD*);
	void setAnte(nodoD*);
};

