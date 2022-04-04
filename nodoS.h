#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class nodoS
{ private:
	int dato;
	nodoS* sgte; // sgte es un puntero al siguiente nodo
  public:
	  nodoS(); // constructor de la clase
	  nodoS(int); // contructor sobrecargad
	  int getDato();
	  nodoS *getSgte();
	  void setDato(int);
	  void setSgte(nodoS *);

};


