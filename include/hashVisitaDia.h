/*
  Módulo de definición de 'THashVisitaDia'.

  Los elementos de tipo THashVisitaDia almacenan una colección de TVisitaDia en forma de tabla 
  de dispersión (hash).

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef HASHVISITADIA_H
#define HASHVISITADIA_H
#include "visitaDia.h"

// Define el tipo THashVisitaDia como un puntero a rep_hashvisitadia
typedef struct rep_hashvisitadia *THashVisitaDia;

// Función para crear un nuevo hash de visitaDia. La representación debe 
// ser un hash de dispersión abierta. El parámetro cantEstimadas
// indica la cantidad de visitaDia que se espera almacenar en esta estructura. 
THashVisitaDia crearTHashVisitaDia(int cantEstimadas);

// Agrega una visita dia a la estructura, insertando en la posición
// brindad por la función de hash (utilizando la fecha de la visitaDia). Si ya existe una visitaDia
// en dicha posición del hash, la agrega a dicha lista, insertando adelante. 
// La función es O(1) peor caso.
// PRE: no existe una visitaDia con la misma fecha en la estructura.
void agregarVisitaDiaTHashVisitaDia(THashVisitaDia hash, TVisitaDia visitaDia);

// Imprime el hash de visitas día de la siguiente forma:
// Para cada posición i entre 0 y cantEstimadas del hash:
//     Si no hay una visita dia guardada en dicha posición, imprime
//        No hay elementos guardados la posicion i de la tabla
//     Si hay visitas dia las imprime en el orden que aparecen, utilizando la función imprimirTVisitaDia.
void imprimirTHashVisitaDia(THashVisitaDia hash);

// Devuelve true si existe una visitaDia para la fecha indicada y false en caso contrario.
// La función es O(1) caso promedio.
bool perteneceVisitaDiaTHashVisitaDia(THashVisitaDia hash, TFecha fecha);

// Obtiene la visitaDia para la fecha indicada. Si no existe una visitaDia para la fecha
// indicada devuelve NULL. 
// La función es O(1) caso promedio.
TVisitaDia obtenerVisitaDiaTHashVisitaDia(THashVisitaDia hash, TFecha fecha);

// Función que libera la memoria asignada para el hash visita dia. 
// También libera la memoria de los visitaDia que se encuentren en la estructura.
// Finalmente, modifica el valor hash para que apunte a NULL;
// Ejecuta en O(n) peor caso, donde n es la cantidad de visitaDia en el hash.
void liberarTHashVisitaDia(THashVisitaDia &hash);

#endif // HASHVISITADIA_H  
