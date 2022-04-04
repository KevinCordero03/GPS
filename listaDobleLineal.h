#pragma once
#include "nodoD.h"

class listaDobleLineal
{
private:
	nodoD* cab;
	int largo;

public:
	listaDobleLineal();
	nodoD* getCab();
	int getLargo();

	void setCab(nodoD*);
	void setLargo(int);

	//Operaciones miscelaneas
	nodoD* ultimo(); //Direcci�n del �ltimo nodo de la lista
	bool esVacia();
	nodoD* dirNodo(int);
	nodoD* anterior(int);

	int pos(int);// Devuelve la posici�n cardinal del int _dato
	int demeDato(int); //Devuelve el _dato en la posici�n int 



	/// OPERACIONES DE AGREGAR
	void agregarInicio(int);
	void agregarFinal(int);
	bool agregarAntesDe(int, int);
	bool agregarDespuesDe(int, int); //Tarea: agrega _dato luego de ref.
	bool agregarPos(int, int); //Tarea: agrega _dato en la pos especificada
	bool agregarAsc(int);
	bool agregarDesc(int);

	//OPERACIONES DE ELIMINAR
	bool eliminar(int);
	bool eliminarLista(); // Elimina todos los elementos de la lista.
	bool eliminarTodos(int); // Recibe de par�metro x y elimina todas las apariciones de x.
	bool eliminarRepetidosConsecutivos(); // Supuesto que todos los valores iguales est�n juntos.
	bool eliminarRepetidosNoConsecutivos(); // Supuestos los repetidos pueden estar juntos o no. O(n^2)
	bool eliminaPos(int); // Elimina de la lista el nodo en la posici�n int _pos.
					   // Considere que la primera posici�n es 0.
					   // Considere que la �ltima posici�n es largo -1.

	// DESPLEGAR
	void desplegarLista();
};

