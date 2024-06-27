/*
  Módulo de definición de 'TListaExposiciones'.

  Los estructura de tipo TListaExposiciones es una lista de exposiciones.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef LISTAEXPOSICIONES_H
#define LISTAEXPOSICIONES_H

#include "utils.h"
#include "exposicion.h"

typedef struct rep_listaexposiciones* TListaExposiciones;

// Función para crear un elemento de tipo TListaExposiciones.
// Devuelve una lista vacía.
// La función es O(1) peor caso.
TListaExposiciones crearTListaExposicionesVacia();

// Función para agregar una exposicion a una lista de exposiciones.
// Inserta la lista en la lista de exposiciones ordenada de menor a mayor por 
// fecha de inicio de la exposicion. En caso de empate la exposición se 
// almacena antes de las existentes con misma fecha. 
// La función es O(n) peor caso, siendo n la cantidad de exposiciones en la lista
// PRE: no existe exposicion con el mismo id en la lista
void agregarExposicionTListaExposiciones(TListaExposiciones &listaExposiciones, TExposicion expo);

// Funcion para verificar si una lista de exposiciones es vacia. Retorna true si y solo si la lista es vacia
// La función es O(1) peor caso
bool esVaciaTListaExposiciones(TListaExposiciones exposiciones);

// Función para imprimir todas las exposiciones de una lista de exposiciones.
// El formato en el que se debe imprimir la lista es utilizando de forma secuencial la función imprimirTExposicion.
// Si la lista es vacía no imprime nada.
// La función es Theta(n) peor caso, siendo n la cantidad de exposiciones en la lista de exposiciones.
void imprimirTListaExposiciones(TListaExposiciones listaExposiciones);

// Función para verificar si una exposición existe en la lista de exposiciones.
// Recibe una lista de exposiciones y un id de exposición y regresa un booleano indicando si pertenece a la lista .
// La función es O(n) peor caso, siendo n la cantidad de exposiciones en la lista.
bool perteneceExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo);

// Función para obtener una exposición de una lista de exposiciones.
// Recibe una lista de exposiciones y un id de exposición y regresa la exposición con ese id.
// La función es O(n) peor caso, siendo n la cantidad de exposiciones en la lista
// PRE: La exposición pertenece a la lista.
TExposicion obtenerExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo);

// Función para liberar una lista de exposiciones
// Recibe una referencia a un elemento de tipo TListaExposiciones y libera su memoria
// Si 'liberarExposiciones' es true, Libera además la memoria de cada una de las exposiciones en la colección.
// La función es O(n) peor caso, siendo n la cantidad de exposiciones en la lista.
void liberarTListaExposiciones(TListaExposiciones &listaExposiciones, bool liberarExposiciones);

// Dada una lista de exposiciones y una fecha, devuelve una nueva lista de exposiciones con las exposiciones
// que finalizaron. Remueve las exposiciones finalizadas de la lista parámetro.
// La función es O(n) peor caso, donde n es la cantidad de exposiciones de la lista. 
TListaExposiciones obtenerExposicionesFinalizadas(TListaExposiciones &listaExposiciones, TFecha fecha);

// Dada una lista de exposiciones y una fecha, devuelve una nueva lista de exposiciones con las exposiciones
// que están activas. Remueve las exposiciones activas de la lista parámetro.
// La función es O(n) peor caso, donde n es la cantidad de exposiciones de la lista.
TListaExposiciones obtenerExposicionesActivas(TListaExposiciones &listaExposiciones, TFecha fecha);

// Dada una lista de exposiciones y otra exposicion, devuelve true si la exposicion
// es compatible con todas las exposiciones de la lista.
// La función es O(n) peor caso, donde n es la cantidad de exposiciones de la lista.
bool esCompatibleTListaExposiciones(TListaExposiciones listaExposiciones, TExposicion expo);

// Dadas dos listas de exposiciones, devuelve una nueva lista de exposiciones con 
// todos los elementos de ambas listas.
// La función es O(n1 + n2) peor caso, donde n es la cantidad de cantidad de exposiciones en
// la primera lista y n2 la cantidad de exposiciones en la segunda lista.
TListaExposiciones unirListaExposiciones(TListaExposiciones listaExpo1, TListaExposiciones listaExpo2);


// Agregados tarea 4:


// Función para obtener la cantidad de exposiciones en la lista de exposiciones.
// La funcion es O(n) peor caso, siendo n la cantidad de exposiciones en la lista.
int cantidadExposicionesTListaExposiciones(TListaExposiciones listaExpo);

// Función para obtener una exposición de la lista dado su índice.
// La funcion es O(n) peor caso, siendo n la cantidad de exposiciones en la lista de exposiciones.
// La primer exposición de la lista tiene índice 1.
// PRE: cantidadExposicionesListaExposiciones(grupo) >= n
// PRE: n > 0 
TExposicion obtenerNesimaExposicionTListaExposiciones(TListaExposiciones listaExpo, int n);


#endif  // LISTAEXPOSICIONES_H
