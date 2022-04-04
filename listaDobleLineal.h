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
	nodoD* ultimo(); //Dirección del último nodo de la lista
	bool esVacia();
	nodoD* dirNodo(int);
	nodoD* anterior(int);

	int pos(int);// Devuelve la posición cardinal del int _dato
	int demeDato(int); //Devuelve el _dato en la posición int 



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
	bool eliminarTodos(int); // Recibe de parámetro x y elimina todas las apariciones de x.
	bool eliminarRepetidosConsecutivos(); // Supuesto que todos los valores iguales están juntos.
	bool eliminarRepetidosNoConsecutivos(); // Supuestos los repetidos pueden estar juntos o no. O(n^2)
	bool eliminaPos(int); // Elimina de la lista el nodo en la posición int _pos.
					   // Considere que la primera posición es 0.
					   // Considere que la última posición es largo -1.

	// DESPLEGAR
	void desplegarLista();
};

