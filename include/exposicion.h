/*
  Módulo de definición de 'TExposicion'.

  Los elementos de tipo TExposicion representan una exposición. La misma tiene un id, una fecha
  de inicio, una fecha de fin, y un conjuntoPiezas indicando cuáles son las piezas que 
  forman parte de la exposición.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef EXPOSICION_H
#define EXPOSICION_H

#include "fecha.h"
#include "pieza.h"
#include "conjuntoPiezas.h"

// Definición de tipo TExposicion como un puntero a rep_exposicion
typedef struct rep_exposicion* TExposicion;

// Función para crear una nueva exposicion.
// Devuelve un conjunto vacío.
// La funcion es O(n) peor caso, siendo n la cantidad máxima de piezas en la exposición.
TExposicion crearTExposicion(int idExpo, TFecha ini, TFecha fin, int cantMax);

// Actualiza la exposición para indicar que la pieza p forma parte de la exposición.
// La función es O(1) peor caso.
// PRE: p no pertenece a la exposición.
void agregarATExposicion(TExposicion& expo, TPieza p);

// Devuelve true si la pieza p forma parte de la exposición.
// La función es O(1) peor caso. 
bool perteneceATExposicion(TExposicion expo, TPieza p);

// Retorna el id de la exposición.
// La función es O(1) peor caso.
int idTExposicion(TExposicion expo);

// Imprime la exposición con el siguiente formato:
//  Exposicion #<id> del <fechaIni> al <fechaFin>
//  Piezas: <lista piezas>
// La <lista piezas> se imprime con el formato dado por 'conjuntoPiezas'
// La función es O(n) donde en es el número máximo de piezas en la exposición.
void imprimirTExposicion(TExposicion expo);

// Retorna la fecha inicio de la exposición.
// La función es O(1) peor caso.
TFecha fechaInicioTExposicion(TExposicion expo);

// Retorna la fecha fin de la exposición.
// La función es O(1) peor caso.
TFecha fechaFinTExposicion(TExposicion expo);

// Devuelve true si las exposiciones expo1 y expo2 son compatibles. Una exposición es 
// compatible con otra si no comparten piezas durante un mismo período de tiempo. O
// de otra manera, no son compatibles si coinciden en el tiempo y además una misma
// pieza es parte de ambas exposiciones.
bool sonExposicionesCompatibles(TExposicion expo1, TExposicion expo2);

// Procedimiento para liberar la memoria asignada a una exposicion.
void liberarTExposicion(TExposicion &expo);

// Agregados tarea 4

// Devuelve una referencia al conjunto de piezas de la exposición.
// La función es O(1) peor caso.
TConjuntoPiezas obtenerPiezasTExposicion(TExposicion expo);

#endif  // EXPOSICION_H