#include "listaSimple.h"

listaSimple::listaSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

nodoS* listaSimple::getCab()
{
	return this->cab;
}

int listaSimple::getLargo()
{
	return this->largo;
}

void listaSimple::setCab(nodoS* _cab)
{
	this->cab = _cab;
}

void listaSimple::setLargo(int _largo)
{
	this->largo = _largo;
}

nodoS* listaSimple::ultimo()
{
	nodoS* ult = NULL;

	if (!esVacia()) {
		int n = getLargo();
		ult = getCab();
		for (int i = 1; i < n; i++)
			ult = ult->getSgte();
	}
	
	return ult;
}

bool listaSimple::esVacia()
{
	return cab == NULL;
}

nodoS* listaSimple::dirNodo(int _dato)
{
	nodoS* aux = NULL;

	if (!esVacia()) {
		aux = getCab();
		bool encontrado = false;

		while (aux != NULL && !encontrado) {
			if (aux->getDato() == _dato)
				encontrado = true;
			else
				aux = aux->getSgte();
		}
	}
	return aux;
}

nodoS* listaSimple::anterior(int _dato)
{
	nodoS* ant = NULL;

	if (largo > 2) {
		bool encontrado = false;
		ant = getCab();
		while (!encontrado && ant->getSgte() != NULL) {
			if (ant->getSgte()->getDato() == _dato)
				encontrado = true;
			else
				ant = ant->getSgte();
		}
		if (!encontrado)
			ant = NULL;
	}
	return ant;
}

int listaSimple::pos(int _dato)
{ 
	nodoS* aux = NULL;
	int pos = -1;
	int largo = getLargo();
	bool encontrado = false;

	if (!esVacia()) {
		aux = getCab();
		for (int i = 0; i < largo; i++) {
			if (aux->getDato() == _dato) {
				pos = i;
				encontrado = true;
				break;
			}else {
				aux = aux->getSgte();
			}
		}
	}
	return pos;
}

int listaSimple::demeDato(int _pos)
{
	nodoS* aux;
	int dato = -1;
	int largo = getLargo();

	if (!esVacia()) {
		if (_pos <= largo || _pos > 0) {
			aux = getCab();
			for (int i = 0; i < largo; i++) {
				if (_pos == i) {
					dato = aux->getDato();
					break;
				}
				else {
					aux = aux->getSgte();
				}
			}
		}
	}
	return dato;
}


/*
* Pasos para agregar en una lista
1. Crear el nuevo nodo
2. Enlazar el nuevo nodo a la lista
3. Reacomodar la lista con el nuevo nodo

*/




void listaSimple::agregarInicio(int _dato)
{

	//Paso #1 : Crear el nuevo nodo
	nodoS* nuevo = new nodoS(_dato);
	//Paso #2 : Enlazar el nuevo nodo a la lista
	nuevo->setSgte(cab);
	//Paso #3: 	Reacomodar la lista con el nuevo nodo
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void listaSimple::agregarFinal(int _dato)
{

	//Paso #1 : Crear el nuevo nodo
	nodoS* nuevo = new nodoS(_dato);
	if (esVacia()){
		setCab(nuevo);
	}
	else {
		nodoS* ult = ultimo();
		ult->setSgte(nuevo);
	}	
	setLargo(getLargo() + 1);

}

bool listaSimple::agregarAntesDe(int ref, int _dato)
{ //Agregar un nodo con el valor de _dato antes de ref

	bool agregado = false;
	if (!esVacia()) {
		if (getCab()->getDato() == ref) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			nodoS* ant = anterior(ref);
			if (ant != NULL) {
				//Paso #1: Crear el nodo
				nodoS* nuevo = new nodoS(_dato);
				//Paso #2 Enlazar el nuevo nodo a la lista
				nuevo->setSgte(ant->getSgte());
				ant->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
		
	}
	return agregado;
	
}

bool listaSimple::agregarDespuesDe(int _ref, int _dato)
{
	bool agregado = false;
	if (!esVacia()) {
		if (ultimo()->getDato() == _ref) {
			agregarFinal(_dato);
			agregado = true;
		}
		else {
			nodoS* aux = dirNodo(_ref);
			if (aux != NULL) {
				//Paso #1: Crear el nodo
				nodoS* nuevo = new nodoS(_dato);
				//Paso #2 Enlazar el nuevo nodo a la lista
				nuevo->setSgte(aux->getSgte());
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

bool listaSimple::agregarPos(int _ref, int _dato)
{
	bool agregado = false;
	nodoS* aux = getCab();
	int largo = getLargo();

	if (!esVacia()) {
		if (_ref <= largo || _ref >= 0) {
			for (int i = 0; i < largo; i++) {
				if (_ref == i) {
					agregarAntesDe(aux->getDato(), _dato);
					agregado = true;
				}
				else {
					aux = aux->getSgte();
				}
			}
		}
	}
	return agregado;
}

bool listaSimple::agregarAsc(int _dato)
{
	bool agregado = false;

	if (esVacia()) {
		setCab(new nodoS(_dato));
		setLargo(1);
		agregado = true;
	}else {
		if (_dato < getCab()->getDato()) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			bool yaExiste = false;
			nodoS* aux = getCab();
			while (aux->getSgte() != NULL && !agregado && !yaExiste) {
				if (aux-> getDato() != _dato) {
					if (_dato < aux->getSgte()->getDato()) {
						// Entonces se agrega el dato
						nodoS* nuevo = new nodoS(_dato); // Paso 1
						// Crea el nodo
						nuevo->setSgte(aux->getSgte()); // Paso 2
						// Enlaza el nodo a la lista
						aux->setSgte(nuevo); // Paso 3
						setLargo(getLargo() + 1);
						agregado = true;
					}
					else {
						aux = aux->getSgte();
					}
				}
				else {
					yaExiste = true;
				}
			}
			if (aux->getSgte()==NULL && !agregado && (aux-> getDato() != _dato)) {
				nodoS* nuevo = new nodoS(_dato); 
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

bool listaSimple::agregarDesc(int _dato)
{
	bool agregado = false;
	if (esVacia()) {
		setCab(new nodoS(_dato));
		setLargo(1);
		agregado = true;
	}
	else {
		if (_dato > getCab()->getDato()) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			bool yaExiste = false;
			nodoS* aux = getCab();
			while (aux->getSgte() != NULL && !agregado && !yaExiste) {
				if (aux->getDato() != _dato) {
					if (_dato > aux->getSgte()->getDato()) {
						// Entonces se agrega el dato
						nodoS* nuevo = new nodoS(_dato); // Paso 1
						// Crea el nodo
						nuevo->setSgte(aux->getSgte()); // Paso 2
						// Enlaza el nodo a la lista
						aux->setSgte(nuevo); // Paso 3
						setLargo(getLargo() + 1);
						agregado = true;
					}else {
						aux = aux->getSgte();
					}
				}
				else {
					yaExiste = true;
				}
			}
			if (aux->getSgte() == NULL && !agregado && (aux->getDato() != _dato)) {
				nodoS* nuevo = new nodoS(_dato);
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

void listaSimple::desplegarLista()
{
	nodoS* aux = getCab();

	if (esVacia()) {
		cout << "Esta vacia la lista" << endl;;
	}
	else {

		while (aux != NULL) {
			cout << aux->getDato() << ",";
			aux = aux->getSgte();
		}
		cout << "fin" << endl;;
	}
}


bool listaSimple::eliminar(int _dato)
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoS* aux;
		if (_dato == getCab()->getDato()) {
			aux = getCab();
			setCab(getCab()->getSgte()); // Apunta al segundo nodo.
			delete aux; // Eliminar el nodo, libera la memoria del nodo.
			setLargo(getLargo() - 1);
			eliminado = true;
		}
		else {
			//En medio
			nodoS* ant = anterior(_dato);
			if (ant != NULL) {
				aux = ant->getSgte(); // Paso 1. Apunto al nodo a eliminar.
				ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
				delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
				setLargo(getLargo() - 1);
				eliminado = true;
			}
		}
	}
	return eliminado;
}

bool listaSimple::eliminarLista()
{
	bool eliminado = false;
	while (!esVacia()) {
		nodoS* aux;
		aux = getCab();
		setCab(getCab()->getSgte());
		delete aux;
		setLargo(getLargo() - 1);
		eliminado = true;
	}
	return eliminado;
}

bool listaSimple::eliminarTodos(int _dato)
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoS* aux;
		nodoS* ant;
		while (_dato == getCab()->getDato()) {
			aux = getCab();
			setCab(getCab()->getSgte()); // Apunta al segundo nodo.
			delete aux; // Eliminar el nodo, libera la memoria del nodo.
			setLargo(getLargo() - 1);	// Ajusta el tamaño de la lista.
			eliminado = true;
		}
		ant = getCab();
		while (ant != ultimo()) {	// En medio
			aux = ant->getSgte(); // Paso 1. Apunto al nodo a eliminar.
			if (_dato == aux->getDato()) {
				ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
				delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
				setLargo(getLargo() - 1);
				eliminado = true;
			}
			else {
				ant = aux;
			}
		}
	}
	return eliminado;
}

bool listaSimple::eliminarRepetidosConsecutivos()
{
	bool eliminado = false;
	if (!esVacia()) {
		nodoS* ant = getCab();
		nodoS* aux;
		while (ant != ultimo()) {
			aux = ant->getSgte(); // Paso 1. Apunto al nodo a eliminar.
			if (ant->getDato() == aux->getDato()) {
				ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
				delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
				setLargo(getLargo() - 1);
				eliminado = true;
			}
			else {
				ant = aux;
			}
		}
	}
	return eliminado;
}

bool listaSimple::eliminarRepetidosNoConsecutivos()
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoS* dato = getCab();
		nodoS* aux;
		nodoS* ant;
		int largo = getLargo();
		int valor;

		for (int i = 0; i < largo -1; i++) {
			ant = dato;
			valor = dato->getDato();
			for (int j = 1 + i; j < largo; j++) {
				aux = ant->getSgte();
				if (valor == aux->getDato()) {
					ant->setSgte(aux->getSgte());
					delete aux;
					setLargo(getLargo() - 1);
					largo--;
					eliminado = true;
				}
				else {
					ant = aux;
				}
			}
			dato = dato->getSgte();
		}
	}
	return eliminado;
}

bool listaSimple::eliminaPos(int _pos)
{
	bool eliminado = false;
	int largo = getLargo();
	nodoS* dato = getCab();
	nodoS* aux;
	nodoS* ant;

	if (!esVacia()) {
		if (_pos >= largo || _pos < 0) {
			eliminado = false;
		}
		else {
			aux = getCab();
			for (int i = 0; i < largo; i++) {
				if (_pos == i && i == 0) {
					setCab(getCab()->getSgte()); // Apunta al segundo nodo.
					delete aux; // Eliminar el nodo, libera la memoria del nodo.
					setLargo(getLargo() - 1);
					eliminado = true;
					break;
				}
				else if (_pos == i && i < largo) {
					//En medio
					ant = anterior(aux->getDato());
					ant->setSgte(aux->getSgte()); // Paso 2. Reacomode las lista sin el nodo.
					delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
					setLargo(getLargo() - 1);
					eliminado = true;
					break;
				}
				else if (i == largo) {
					// Final
					ant = anterior(aux->getDato());
					ant->setSgte(NULL); // Paso 2. Reacomode las lista sin el nodo.
					delete aux; // Paso 3. Eliminar el nodo, liberar el espacio de memoria del nodo.
					setLargo(getLargo() - 1);
					eliminado = true;
					break;
				}else {
					ant = aux;
					aux = ant->getSgte();
				}
			}
		}
	}
return eliminado;
}
