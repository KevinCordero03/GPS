#include "listaDobleCircular.h"

listaDobleCircular::listaDobleCircular()
{
	this->cab = NULL;
	this->largo = 0;
}

nodoD* listaDobleCircular::getCab()
{
	return this->cab;
}

int listaDobleCircular::getLargo()
{
	return this->largo;
}

void listaDobleCircular::setCab(nodoD* _cab)
{
	this->cab = _cab;
}

void listaDobleCircular::setLargo(int _largo)
{
	this->largo = _largo;
}

bool listaDobleCircular::esVacia()
{
	return cab == NULL;
}

nodoD* listaDobleCircular::dirNodo(int _dato)
{
	if (esVacia()) return NULL;
	nodoD* aux = getCab();
	// Recorre toda la lista y compara el valor recibido con el dato del nodo actual
	// Si coinciden entonces devuelve el puntero del nodo actual
	do
	{
		if (aux->getDato() == _dato)
		{
			return aux;
		}
		aux = aux->getSgte();
	} while (aux != getCab());
	return NULL;
}

void listaDobleCircular::agregarInicio(int _dato)
{
	nodoD* nuevo = new nodoD(_dato);
	if (!esVacia()) {
		nuevo->setSgte(cab);
		nuevo->setAnte(cab->getAnte());
		cab->getAnte()->setSgte(nuevo);
		cab->setAnte(nuevo);
		cab = nuevo;
		largo++;
	}
	else {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
		cab = nuevo;
		largo++;
	}
}

void listaDobleCircular::desplegarLista() {
	nodoD* aux = getCab();
	if (!esVacia()) {
		aux = getCab();
		do {
			cout << aux->getDato();
			aux = aux->getSgte();
		} while (aux != getCab());
		cout << "Fin de la lista" << endl;
	}
}

bool listaDobleCircular::agregarAntesDe(int pRef, int pDato)
{
	if (esVacia()) return false;
	// Agregar al inicio
	if (pDato == getCab()->getDato())
	{
		agregarInicio(pDato);
		return true;
	}
	nodoD* nodo = dirNodo(pRef);
	if (nodo == NULL) return false;		// No se puede agregar antes de un elemento que no existe en la lista
	nodoD* nuevo = new nodoD(pDato);
	// Conectar a los existentes
	nuevo->setSgte(nodo);
	nuevo->setAnte(nodo->getAnte());
	// Hacer a los existentes apuntar al nuevo nodo
	nuevo->getAnte()->setSgte(nuevo);
	nuevo->getSgte()->setAnte(nuevo);
	setLargo(getLargo() + 1);
	return true;
}

nodoD* listaDobleCircular::ultimo()
{
	nodoD* ult = NULL;

	if (!esVacia()) {
		int n = getLargo();
		ult = getCab();
		for (int i = 1; i < n; i++)
			ult = ult->getSgte();
	}

	return ult;
}

bool listaDobleCircular::esVacia()
{
	return cab == NULL;
}

nodoD* listaDobleCircular::dirNodo(int _dato)
{
	nodoD* aux = NULL;

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

nodoD* listaDobleCircular::anterior(int _dato)
{
	nodoD* ant = NULL;

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

int listaDobleCircular::pos(int _dato)
{
	nodoD* aux = NULL;
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
			}
			else {
				aux = aux->getSgte();
			}
		}
	}
	return pos;
}

int listaDobleCircular::demeDato(int _pos)
{
	nodoD* aux;
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




void listaDobleCircular::agregarInicio(int _dato)
{

	//Paso #1 : Crear el nuevo nodo
	nodoD* nuevo = new nodoD(_dato);
	//Paso #2 : Enlazar el nuevo nodo a la lista
	nuevo->setSgte(cab);
	//Paso #3: 	Reacomodar la lista con el nuevo nodo
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void listaDobleCircular::agregarFinal(int _dato)
{

	//Paso #1 : Crear el nuevo nodo
	nodoD* nuevo = new nodoD(_dato);
	if (esVacia()) {
		setCab(nuevo);
	}
	else {
		nodoD* ult = ultimo();
		ult->setSgte(nuevo);
	}
	setLargo(getLargo() + 1);

}

bool listaDobleCircular::agregarAntesDe(int ref, int _dato)
{ //Agregar un nodo con el valor de _dato antes de ref

	bool agregado = false;
	if (!esVacia()) {
		if (getCab()->getDato() == ref) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			nodoD* ant = anterior(ref);
			if (ant != NULL) {
				//Paso #1: Crear el nodo
				nodoD* nuevo = new nodoD(_dato);
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

bool listaDobleCircular::agregarDespuesDe(int _ref, int _dato)
{
	bool agregado = false;
	if (!esVacia()) {
		if (ultimo()->getDato() == _ref) {
			agregarFinal(_dato);
			agregado = true;
		}
		else {
			nodoD* aux = dirNodo(_ref);
			if (aux != NULL) {
				//Paso #1: Crear el nodo
				nodoD* nuevo = new nodoD(_dato);
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

bool listaDobleCircular::agregarPos(int _ref, int _dato)
{
	bool agregado = false;
	nodoD* aux = getCab();
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

bool listaDobleCircular::agregarAsc(int _dato)
{
	bool agregado = false;

	if (esVacia()) {
		setCab(new nodoD(_dato));
		setLargo(1);
		agregado = true;
	}
	else {
		if (_dato < getCab()->getDato()) {
			agregarInicio(_dato);
			agregado = true;
		}
		else {
			bool yaExiste = false;
			nodoD* aux = getCab();
			while (aux->getSgte() != NULL && !agregado && !yaExiste) {
				if (aux->getDato() != _dato) {
					if (_dato < aux->getSgte()->getDato()) {
						// Entonces se agrega el dato
						nodoD* nuevo = new nodoD(_dato); // Paso 1
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
			if (aux->getSgte() == NULL && !agregado && (aux->getDato() != _dato)) {
				nodoD* nuevo = new nodoD(_dato);
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

bool listaDobleCircular::agregarDesc(int _dato)
{
	bool agregado = false;
	if (esVacia()) {
		setCab(new nodoD(_dato));
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
			nodoD* aux = getCab();
			while (aux->getSgte() != NULL && !agregado && !yaExiste) {
				if (aux->getDato() != _dato) {
					if (_dato > aux->getSgte()->getDato()) {
						// Entonces se agrega el dato
						nodoD* nuevo = new nodoD(_dato); // Paso 1
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
			if (aux->getSgte() == NULL && !agregado && (aux->getDato() != _dato)) {
				nodoD* nuevo = new nodoD(_dato);
				aux->setSgte(nuevo);
				setLargo(getLargo() + 1);
				agregado = true;
			}
		}
	}
	return agregado;
}

void listaDobleCircular::desplegarLista()
{
	nodoD* aux = getCab();

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


bool listaDobleCircular::eliminar(int _dato)
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoD* aux;
		if (_dato == getCab()->getDato()) {
			aux = getCab();
			setCab(getCab()->getSgte()); // Apunta al segundo nodo.
			delete aux; // Eliminar el nodo, libera la memoria del nodo.
			setLargo(getLargo() - 1);
			eliminado = true;
		}
		else {
			//En medio
			nodoD* ant = anterior(_dato);
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

bool listaDobleCircular::eliminarLista()
{
	bool eliminado = false;
	while (!esVacia()) {
		nodoD* aux;
		aux = getCab();
		setCab(getCab()->getSgte());
		delete aux;
		setLargo(getLargo() - 1);
		eliminado = true;
	}
	return eliminado;
}

bool listaDobleCircular::eliminarTodos(int _dato)
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoD* aux;
		nodoD* ant;
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

bool listaDobleCircular::eliminarRepetidosConsecutivos()
{
	bool eliminado = false;
	if (!esVacia()) {
		nodoD* ant = getCab();
		nodoD* aux;
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

bool listaDobleCircular::eliminarRepetidosNoConsecutivos()
{
	bool eliminado = false;

	if (!esVacia()) {
		nodoD* dato = getCab();
		nodoD* aux;
		nodoD* ant;
		int largo = getLargo();
		int valor;

		for (int i = 0; i < largo - 1; i++) {
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

bool listaDobleCircular::eliminaPos(int _pos)
{
	bool eliminado = false;
	int largo = getLargo();
	nodoD* dato = getCab();
	nodoD* aux;
	nodoD* ant;

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
				}
				else {
					ant = aux;
					aux = ant->getSgte();
				}
			}
		}
	}
	return eliminado;
}