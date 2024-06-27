/*
  Módulo de definición de 'TColeccionPiezas'.

  Los elementos de tipo TColeccionPiezas almacenan una coleccion de elementos de tipo TPieza.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef COLECCIONPIEZAS_H
#define COLECCIONPIEZAS_H

#include "pieza.h"

// Define el tipo TColeccionPiezas como un puntero a rep_coleccionpiezas
typedef struct rep_coleccionpiezas *TColeccionPiezas;

// Función para crear un elemento de tipo TColeccionPiezas.
// Devuelve una colección vacía.
// La función es Theta(1) peor caso.
TColeccionPiezas crearColeccionPiezasVacia();

// Función para agregar una pieza a una colección de piezas.
// Inserta la pieza en la colección de piezas, ordenado de menor a mayor por ID pieza.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la colección
// PRE: no existe pieza con el mismo id en la colección
void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza);

// Función para imprimir todas las piezas de una colección.
// El formato en el que se debe imprimir la colección es utilizando de forma secuencial la función imprimirTPieza.
// Si la colección está vacía no imprime nada.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la coleción.
void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas);

// Función para liberar una colección de piezas
// Recibe una referencia a un elemento de tipo TColeccionPiezas y libera su memoria
// Libera además la memoria de cada una de las piezas en la colección.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la colección.
void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas);

// Funcion para verificar si una coleccion piezas es vacia, retorna true si y solo si la coleccion es vacia
// La función es Theta(1) peor caso
bool esVaciaColeccionPiezas(TColeccionPiezas piezas);

// Función para verificar si una pieza existe en una colección de piezas.
// Recibe una colección de piezas y un id de pieza y regresa un booleano indicando su existencia.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la colección.
bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza);

// Función para obtener una pieza de una colección de piezas.
// Recibe una colección de piezas y un id de pieza y regresa la pieza con ese id.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la coleccion
// PRE: La pieza debe estar en la coleccion
TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza);

// Función para remover una pieza de una colección de piezas
// Recibe una colección de piezas y un id de pieza y elimina la pieza con ese id.
// También elimina la memoria asociada a dicha pieza.
// La función es Theta(n) peor caso, siendo n la cantidad de piezas en la colección
// PRE: La pieza debe estar en la colección
void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza);

#endif // COLECCIONPIEZAS_H  
