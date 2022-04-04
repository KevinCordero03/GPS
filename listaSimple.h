#pragma once
#include <iostream>

#include <stdlib.h>
using namespace std;

#include "nodoS.h"
class listaSimple
{
	private:
		nodoS* cab;
		int largo;

	public:
		listaSimple();
		nodoS *getCab();
		int getLargo();

		void setCab(nodoS *);
		void setLargo(int);

		//Operaciones miscelaneas
		nodoS* ultimo(); //Devuelve el �ltimo nodo de la lista
		bool esVacia(); 
		nodoS* dirNodo(int); //Devuelve la direcci�n del nodo donde se ubica el dato
		nodoS* anterior(int); //Devuelve la direcci�n del nodo anterior al dato

		int pos(int);  // Devuelve la posici�n cardinal del int _dato
		int demeDato(int); //Devuelve el _dato en la posici�n int 
		


		/// OPERACIONES DE AGREGAR
		void agregarInicio(int);  // Agrega el dato al inicio de la lista
		void agregarFinal(int);  // Agrega el dato al final de la lista
		bool agregarAntesDe(int, int); //  Agrega el dato antes de dato referencia, Si ref no existe, devuelve falso
		bool agregarDespuesDe(int, int); //Tarea: agrega _dato luego de ref.
		bool agregarPos(int, int); //Tarea: agrega _dato en la pos especificada
		bool agregarAsc(int);  // 
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
		void sumar();
};

