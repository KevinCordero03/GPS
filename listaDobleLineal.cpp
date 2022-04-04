#include "listaDobleLineal.h"

listaDobleLineal::listaDobleLineal()
{
	this->cab = NULL;
	this->largo = 0;
}

nodoD* listaDobleLineal::getCab()
{
	return this->cab;
}

int listaDobleLineal::getLargo()
{
	return this->largo;
}

void listaDobleLineal::setCab(nodoD* _cab)
{
	this->cab = _cab;
}

void listaDobleLineal::setLargo(int _largo)
{
	this->largo = _largo;
}

bool listaDobleLineal::esVacia()
{
	return cab == NULL;
}

void listaDobleLineal::agregarInicio(int _dato)
{
	nodoD* nuevo = new nodoD(_dato); //Paso #1: Crear el nodo
	//Paso #2: Enlazar el nuevo nodo a la lista
	nuevo->setSgte(cab);
	//Paso #3: Reacomodar la lista con el nuevo nodo
	if (!esVacia())
		cab->setAnte(nuevo);
	cab = nuevo;
	largo++;
}

bool listaDobleLineal::agregarDespuesDe(int _ref, int _dato)
{   //Crear un nodo con _dato luego del nodo con _ref
	bool agregado = false;
	nodoD* aux = dirNodo(_ref);
	if (aux != NULL) { //Lo encontró el nodo con _ref
		//Paso #1: Crear el nodo
		nodoD* nuevo = new nodoD(_dato);
		//Paso #3: Enlazar el nuevo nodo a la lista
		nuevo->setAnte(aux);
		nuevo->setSgte(aux->getSgte());
		//Paso #3 : Reacomodar la lista con el nuevo nodo
		aux->getSgte()->setAnte(nuevo);
		aux->setSgte(nuevo);
		setLargo(getLargo() + 1);
		agregado = true;

	}
	return agregado;
}

bool listaDobleLineal::eliminar(int _dato)
{
	bool eliminado = false;
	//Paso #1: Encontrar el nodo a eliminar
	nodoD* aux = dirNodo(_dato); // Devuelve la dirección del primer nodo con el valor de _dato
	if (aux != NULL) {

		//Paso #2. Reacomodar la lista sin él nodo a eliminar
		if (getCab() != aux)
			aux->getAnte()->setSgte(aux->getSgte());
		else
		setCab(getCab()->getSgte());
		if (aux->getSgte() != NULL)
			aux->getSgte()->setAnte(aux->getAnte());

		delete aux; //Paso #3. Eliminar el nodo
		setLargo(getLargo() - 1);
		eliminado = true;
	}
	return eliminado;

}

void listaDobleLineal::desplegarLista() {
	nodoD* aux = getCab();
	while (aux != NULL)
		cout << aux->getDato();
	aux = aux->getSgte();
}

nodoD* listaDobleLineal::ultimo()
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

bool listaDobleLineal::esVacia()
{
	return cab == NULL;
}

nodoD* listaDobleLineal::dirNodo(int _dato)
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

nodoD* listaDobleLineal::anterior(int _dato)
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

int listaDobleLineal::pos(int _dato)
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

int listaDobleLineal::demeDato(int _pos)
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




void listaDobleLineal::agregarInicio(int _dato)
{

	//Paso #1 : Crear el nuevo nodo
	nodoD* nuevo = new nodoD(_dato);
	//Paso #2 : Enlazar el nuevo nodo a la lista
	nuevo->setSgte(cab);
	//Paso #3: 	Reacomodar la lista con el nuevo nodo
	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void listaDobleLineal::agregarFinal(int _dato)
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

bool listaDobleLineal::agregarAntesDe(int ref, int _dato)
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

bool listaDobleLineal::agregarDespuesDe(int _ref, int _dato)
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

bool listaDobleLineal::agregarPos(int _ref, int _dato)
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

bool listaDobleLineal::agregarAsc(int _dato)
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

bool listaDobleLineal::agregarDesc(int _dato)
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

void listaDobleLineal::desplegarLista()
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


bool listaDobleLineal::eliminar(int _dato)
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

bool listaDobleLineal::eliminarLista()
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

bool listaDobleLineal::eliminarTodos(int _dato)
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

bool listaDobleLineal::eliminarRepetidosConsecutivos()
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

bool listaDobleLineal::eliminarRepetidosNoConsecutivos()
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

bool listaDobleLineal::eliminaPos(int _pos)
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