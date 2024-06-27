/*
  Módulo de definición de 'TConjuntoPiezas'.

  Los estructura de tipo TConjuntoPiezas es un conjunto acotado que almacena ids de piezas.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef CONJUNTOPIEZAS_H
#define CONJUNTOPIEZAS_H

#include "utils.h"

#define MAX_PIEZAS 100

// Definición de tipo TConjuntoPiezas como un puntero a rep_conjuntopiezas
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de identificadores que almacena
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
typedef struct rep_conjuntopiezas* TConjuntoPiezas;

// Función para crear un nuevo conjunto de piezas.
// Devuelve un conjunto vacíol
// La funcion es Theta(n) peor caso, siendo n la cantidad máxima de elementos del conjunto
TConjuntoPiezas crearTConjuntoPiezas(int cantMax);

// Función para determinar si un conjunto de piezas es vacío
// Devuelve true si el conjunto es vacío, false en otro caso
// La funcion es O(1) peor caso
bool esVacioTConjuntoPiezas(TConjuntoPiezas c);

// Procedimiento para insertar el identificador "id" en el conjunto de v "c".
// Si "id" no pertenece al rango válido de ids del conjunto "c" la función no hace nada.
// Si "id" ya pertenece al conjunto, la función no hace nada.
// La función es O(1) peor caso.
void insertarTConjuntoPiezas(TConjuntoPiezas &c, int id); 

// Procedimiento para borrar al "id" del conjunto de piezas "c"
// Si "id" no pertenece al conjunto "c" la función no hace nada
// La función es O(1) peor caso
void borrarDeTConjuntoPiezas(TConjuntoPiezas &c, int id);

// Función para determinar si el identificador "id" pertenece al conjunto "c"
// Devuelve true si pertenece, false en otro caso
// La funcion es O(1) peor caso
bool perteneceTConjuntoPiezas(TConjuntoPiezas c, int id);

// Función que retorna la cantidad de elementos del conjunto de piezas "c".
// La función es O(1) peor caso.
int cardinalTConjuntoPiezas(TConjuntoPiezas c);

// Función que retorna la cantidad máxima de elementos del conjunto de piezas "c".
// La función es O(1) peor caso.
int cantMaxTConjuntoPiezas(TConjuntoPiezas c);

// Procedimiento para imprimir el conjunto de piezas.
// Imprime los ids de las piezas del conjunto ordenado de menor a mayor.
// Deben imprimirse solamente los elementos, separados por un espacio, con un salto de línea al final.
// Ejemplo: si el conjunto "c" tiene los elementos 7, 29, 42 y 75 la impresión debe ser "7 29 42 75 ".
// La función es O(n) peor caso, siendo "n" la cantidad máxima de elementos de "c".
void imprimirTConjuntoPiezas(TConjuntoPiezas c);

// Procedimiento para liberar la memoria asignada a un conjunto de piezas.
// La funcion es O(1) peor caso.
void liberarTConjuntoPiezas(TConjuntoPiezas &c);

// Función que retorna la unión entre los conjuntos de piezas "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoPiezas unionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2);

// Función que retorna la intersección entre los conjuntos de c "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoPiezas interseccionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2);

// Función que retorna la diferencia entre los conjuntos de Piezas "c1" y "c2".
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n".
// La función es O(n) peor caso.
TConjuntoPiezas diferenciaTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2);

#endif  // CONJUNTOPIEZAS_H
