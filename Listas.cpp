// Listas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "listaSimple.h"
#include "listaDobleLineal.h"


void menuListaSimple(listaSimple *& LS, listaDobleLineal*& LD) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE LISTAS " << endl;
        cout << endl;
        cout << "(1)  Desplegar la lista " << endl;
        cout << "(2)  Status de la lista: " << endl;
        cout << "(3)  Agregar al inicio " << endl;
        cout << "(4)  Agregar al final " << endl;
        cout << "(5)  Agregar antes de un dato de la lista " << endl;
        cout << "(6)  Agregar despues de un dato de la lista " << endl;
        cout << "(7)  Agregar un dato en la posicion especificada " << endl;
        cout << "(8)  Agregar ascendente " << endl;
        cout << "(9)  Agregar descendente " << endl;
        cout << "(10) Despliega la posicion actual del dato en la lista " << endl;
        cout << "(11) Despliega el dato de acuerdo a la posicion de la lista " << endl;
        cout << "(12) Eliminar valor" << endl;
        cout << "(13) Eliminar lista" << endl;
        cout << "(14) Eliminar todos los valores segun parametro" << endl;
        cout << "(15) Eliminar todos los valores repetidos consecutivos" << endl;
        cout << "(16) Eliminar todos los valores repetidos " << endl;
        cout << "(17) Eliminar posicion " << endl;
        cout << "(18) Sumar lista " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;
    
        switch (opc) {
        case 1: {
            cout << "Desplegar la lista"<<endl;
            LS->desplegarLista();
            break;
        }
        case 2: {
            cout << "Status de la lista: " << endl;
            cout << "Largo de la lista =" << LS->getLargo() << endl;
            if (LS->esVacia())
                cout << "La lista está vacia " << endl;
            else
                cout << "La lista no esta vacia " << endl;
       
            break;
        }
        case 3: {
            cout << "Agregar al inicio " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LS->agregarInicio(dato);
            break; 
        }
        case 4: {
            cout << "Agregar al final " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LS->agregarFinal(dato);
            break; }
        case 5: {
            cout << "Agregar en medio (antes de... ) " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;

            int ref;
            cout << "Agregar " << dato << " antes de : ";
            cin >> ref;
                   
            if (LS->agregarAntesDe(ref, dato))
                cout << "Se ha agregado exitosamente " << dato << " antes de " << ref << endl;
            else
                cout << ref << " no existe en la lista, no se ha agregado "<< dato << "en la lista." << endl;
                
            break; 
        }
        case 6: {
            cout << "Agregar en medio (despues de... ) " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;

            int ref;
            cout << "Agregar " << dato << " despues de : ";
            cin >> ref;

            if (LS->agregarDespuesDe(ref, dato))
                cout << "Se ha agregado exitosamente " << dato << " despues de " << ref << endl;
            else
                cout << ref << " No existe en la lista, no se ha agregado " << dato << "en la lista." << endl;

            break;
        }
        case 7: {
            cout << "Agregar un dato en la posicion especificada " << endl;
            int ref;
            cout << "Posicion en la que se va a agregar el dato->";
            cin >> ref;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            if (LS->agregarPos(ref, dato)) {
                cout << "El dato: " << dato << " fue agregado en la posicion: " << ref;
            }
            else {
                cout << "El dato no se pudo agregar";
            }
            break;
        }
        case 8: {
            cout << "Agregar ascendente " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LS->agregarAsc(dato);
            break;
        }
        case 9: {
            cout << "Agregar descendente " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LS->agregarDesc(dato);
            break;
        }
        case 10: {
            cout << "Despliega la posicion actual del dato en la lista " << endl;
            int dato;
            cout << "Dato para averiguar la posicion->";
            cin >> dato;
            int valor = LS->pos(dato);
            if (valor >= 
                0) {
                cout << "La posicion del dato es: " << valor << endl;
            }
            else {
                cout << "El dato no existe en la lista.";
            }
            break;
        }
        case 11: {
            cout << "Despliega el dato de acuerdo a la posicion de la lista " << endl;
            int dato;
            cout << "Posicion para averiguar el dato->";
            cin >> dato;
            int valor = LS->demeDato(dato);
            if (valor >= 0) {
                cout << "El valor del dato es: " << valor << endl;
            }
            else {
                cout << "La posicion no existe en la lista.";
            }
            break;
        }
        case 12: {
            cout << "Eliminar valor " << endl;
            int dato;
            cout << "Dato a eliminar->";
            cin >> dato;
            if (LS->eliminar(dato)) {
                cout << "El dato: " << dato << " fue eliminado correctamente";
            }
            else {
                cout << "El dato no se puede eliminar, o no existe";
            }
            break;
        }
        case 13: {
            cout << "Eliminar lista " << endl;
            if (LS->eliminarLista()) {
                cout << "Lista eliminada";
            }
            else {
                cout << "La lista no existe o no se puede eliminar";
            }
            break;
        }

        case 14: {
            cout << "Eliminar todos los valores segun parametro " << endl;
            int dato;
            cout << "Dato a eliminar->";
            cin >> dato;
            if (LS->eliminarTodos(dato)) {
                cout << "Se eliminaron todos los datos segun el parametro: " << dato;
            }
            else {
                cout << "No se pudieron eliminar los datos segun parametro, o no existen";
            }
            break;
        }
        case 15: {
            cout << "Eliminar todos los valores repetidos consecutivos" << endl;
            if (LS->eliminarRepetidosConsecutivos()) {
                cout << "Todos los valores repetidos consecutivos, fueron eliminados";
            }
            else {
                cout << "No se pudieron eliminar los valores repetidos, o no existen";
            }
            break;
        }
        case 16: {
            cout << "Eliminar todos los valores repetidos " << endl;
            if (LS->eliminarRepetidosNoConsecutivos()) {
                cout << "Todos los valores repetidos fueron eliminados";
            }
            else {
                cout << "No se pudieron eliminar los valores repetidos, o no existen";
            }
            break;
        }
        case 17: {
            cout << "Eliminar posicion " << endl;
            int dato;
            cout << "Posicion a eliminar->";
            cin >> dato;
            if (LS->eliminaPos(dato)) {
                cout << "Posicion " << dato << " eliminada";
            }
            else {
                cout << "No se pudo eliminar la posicion o no existe";
            }
            break;
        }
        case 0: {
            cout << "Finalizando aplicacion.... Adios.... "<< endl;
            break; 
        }
        default:
            cout << "Opcion digitada no es válida "<< endl;
                break;
     }
    
        cout << endl << endl;
    
    } while (opc != 0);


}
/*
void menuListaDobleLineal(listaDobleLineal*& LDL) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE LISTAS " << endl;
        cout << endl;
        cout << "(1)  Desplegar la lista " << endl;
        cout << "(2)  Status de la lista: " << endl;
        cout << "(3)  Agregar al inicio " << endl;
        cout << "(4)  Agregar al final " << endl;
        cout << "(5)  Agregar antes de un dato de la lista " << endl;
        cout << "(6)  Agregar despues de un dato de la lista " << endl;
        cout << "(7)  Agregar un dato en la posicion especificada " << endl;
        cout << "(8)  Agregar ascendente " << endl;
        cout << "(9)  Agregar descendente " << endl;
        cout << "(10) Despliega la posicion actual del dato en la lista " << endl;
        cout << "(11) Despliega el dato de acuerdo a la posicion de la lista " << endl;
        cout << "(12) Eliminar valor" << endl;
        cout << "(13) Eliminar lista" << endl;
        cout << "(14) Eliminar todos los valores segun parametro" << endl;
        cout << "(15) Eliminar todos los valores repetidos consecutivos" << endl;
        cout << "(16) Eliminar todos los valores repetidos " << endl;
        cout << "(17) Eliminar posicion " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
        case 1: {
            cout << "Desplegar la lista" << endl;
            LDL->desplegarLista();
            break;
        }

        case 2: {
            cout << "Status de la lista: " << endl;
            cout << "Largo de la lista =" << LDL->getLargo() << endl;
            
            if (LDL->esVacia())
                cout << "La lista está vacia " << endl;
            else
                cout << "La lista no esta vacia " << endl;
            break;
        }
        case 3: {
            cout << "Agregar al inicio " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LDL->agregarInicio(dato);
            break;
        }
        case 4: {
            cout << "Agregar al final " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LDL->agregarFinal(dato);
            break; 
        }
        case 5: {
            cout << "Agregar en medio (antes de... ) " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;

            int ref;
            cout << "Agregar " << dato << " antes de : ";
            cin >> ref;
            if (LDL->agregarAntesDe(ref, dato))
                cout << "Se ha agregado exitosamente " << dato << " antes de " << ref << endl;
            else
                cout << ref << " no existe en la lista, no se ha agregado " << dato << "en la lista." << endl;
            break;
        }
        case 6: {
            cout << "Agregar en medio (despues de... ) " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;

            int ref;
            cout << "Agregar " << dato << " despues de : ";
            cin >> ref;
            if (LDL->agregarAntesDe(ref, dato))
                cout << "Se ha agregado exitosamente " << dato << " despues de " << ref << endl;
            else
                cout << ref << " no existe en la lista, no se ha agregado " << dato << "en la lista." << endl;
            break;
        }
        case 7: {
            cout << "Agregar un dato en la posicion especificada " << endl;
            break;
        }
        case 8: {
            cout << "Agregar ascendente " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LDL->agregarAsc(dato);
            break;
        }
        case 9: {
            cout << "Agregar descendente " << endl;
            int dato;
            cout << "Dato para agregar a la lista->";
            cin >> dato;
            LS->agregarDes(dato);
            break;
        }
        case 10: {
            cout << "Despliega la posicion actual del dato en la lista " << endl;
            int dato;
            cout << "Dato para averiguar la posicion->";
            cin >> dato;
            LDL->pos(dato);
            break;
        }
        case 11: {
            cout << "Despliega el dato de acuerdo a la posicion de la lista " << endl;
            int dato;
            cout << "Posicion de la lista para averiguar dato->";
            cin >> dato;
            LDL->demeDato(dato);
            break;
        }
        case 12: {
            cout << "Eliminar valor " << endl;
            int dato;
            cout << "Dato a eliminar->";
            cin >> dato;
            LDL->eliminar(dato);
            break;
        }
        case 13: {
            cout << "Eliminar lista " << endl;
            break;
        }

        case 14: {
            cout << "Eliminar todos los valores segun parametro " << endl;
            int dato;
            cout << "Dato a eliminar->";
            cin >> dato;
            LDL->eliminarTodos(dato);
            break;
        }
        case 15: {
            cout << "Eliminar todos los valores repetidos consecutivos" << endl;
            LDL->eliminarRepetidosConsecutivos();
            break;
        }
        case 16: {
            cout << "Eliminar todos los valores repetidos " << endl;
            LDL->eliminarRepetidosNoConsecutivos();
            break;
        }
        case 17: {
            cout << "Eliminar posicion " << endl;
            int dato;
            cout << "Posicion a eliminar->";
            cin >> dato;
            LDL->eliminaPos(dato);
            break;
        }
        case 0: {
            cout << "Finalizando aplicacion.... Adios.... " << endl;
            break;
        }
        default:
            cout << "Opcion digitada no es válida " << endl;
            break;
        }

        cout << endl << endl;

    } while (opc != 0);


}
*/
int main()
{
    cout << "INTERFACE MANEJO DE LISTAS\n" << endl;
    listaSimple* LS = new listaSimple();
    listaDobleLineal* LDL = new listaDobleLineal();
    menuListaSimple(LS,LDL);

    /*
    cout << "INTERFACE MANEJO DE LISTAS DOBLE LINEAL\n" << endl;
    listaDobleLineal* LDL = new listaDobleLineal();
    menuListaDobleLineal(LDL);
    */

    return 0;
}
