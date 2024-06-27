/*
  Módulo de definición de 'TPieza'.

  Los elementos de tipo TPieza son elementos que almacenan un id, el nombre de la pieza,
  el nombre y apellido del autor y una fecha de creación.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef PIEZA_H
#define PIEZA_H

#include <string.h>

#include "fecha.h"

// Constante para definir el largo máximo de la nombre y apellido de una pieza
const int MAX_NOMBRE_PIEZA = 100;
const int MAX_NOMBRE_AUTOR = 100;
const int MAX_APELLIDO_AUTOR = 100;

// Define el tipo TPieza como un puntero a rep_pieza
typedef struct rep_pieza *TPieza;

// Función que crea un elemento de tipo TPieza con los valores pasador como parámetro
// Ejecuta en O(1) peor caso.
TPieza crearTPieza(int id, const char nombrePieza[MAX_NOMBRE_PIEZA], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], TFecha fechaCreacion);

// Función que retorna el id de la pieza
// Ejecuta en O(1) peor caso.
int idTPieza(TPieza pieza);

// Función que imprime la información de la pieza en el siguiente formato:
  // Pieza: <Id>
  // <NombrePieza>-<NombreAutor> <ApellidoAutor>
  // Creada en: <Fecha>
// Ejecuta en O(1) peor caso
void imprimirTPieza(TPieza pieza);

// Función que libera la memoria asociada a una pieza
// Ejecuta en O(1) peor caso
void liberarTPieza(TPieza &pieza);

#endif  // PIEZA_H