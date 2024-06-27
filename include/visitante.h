/*
  Módulo de definición de 'TVisitante'.

  Los elementos de tipo TVisitante son elementos que almacenan un id, un nombre, un apellido y una edad.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef VISITANTE_H
#define VISITANTE_H

#include <string.h>

#include "fecha.h"
#include "conjuntoPiezas.h"

// Constante para definir el largo máximo de la nombre y apellido de una visitante
const int MAX_NOMBRE = 100;
const int MAX_APELLIDO = 100;

// Define el tipo TVisitante como un puntero a rep_visitante
typedef struct rep_visitante *TVisitante;

// Función que imprime la información de la visitante en el siguiente formato:
  // Visitante <nombre> <apellido>
  // Id: <idVisitante>
  // Edad: <edad>
// Ejecuta en O(1) peor caso
void imprimirTVisitante(TVisitante visitante);


// Función que retorna el nombre del visitante
// Ejecuta en O(1) peor caso
void nombreTVisitante(TVisitante visitante, char nombre[MAX_NOMBRE]);

// Función que retorna el apellido del visitante
void apellidoTVisitante(TVisitante visitante, char apellido[MAX_APELLIDO]);

// Función que retorna el id del visitante
// Ejecuta en O(1) peor caso
int idTVisitante(TVisitante visitante);

// Función que retorna la edad del visitante
// Ejecuta en O(1) peor caso
int edadTVisitante(TVisitante visitante);

// Función que copia un visitante. La copia no comparte memoria con el visitante pasado por parámetro.
// Ejecuta en O(1) peor caso
TVisitante copiarTVisitante(TVisitante visitante);


// AGREGADOS TAREA 4

// Agrega una pieza a las piezas favoritas del visitante.
// Ejecuta en O(1) peor caso.
void agregarPiezaFavoritaTVisitante(TVisitante visitante, int idPieza);
 
// Devuelve la instancia de TConjuntoPiezas que indica las piezas
// favoritas del visitante.
// Ejecuta en O(1) peor caso.
TConjuntoPiezas obtenerPiezasFavoritasTVisitante(TVisitante visitante);

// Funciones a modificar 

// Función que crea un elemento de tipo TVisitante con los valores pasados por parámetro
// Ejecuta en O(1) peor caso
// Nuevo: también reserva memoria para el conjunto de piezas favoritas del visitante utilizando
// la constante MAX_PIEZAS definida en conjuntoPiezas.h
TVisitante crearTVisitante(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad);

// Función que libera la memoria asignada para un visitante
// Ejecuta en O(1) peor caso
// Nuevo: también libera la memoria asociada al conjunto de piezas favoritas.
void liberarTVisitante(TVisitante &visitante);

#endif  // VISITANTE_H