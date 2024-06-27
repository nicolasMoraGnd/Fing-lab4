/*
  Módulo de definición de 'TColeccionGrupos'.

  Los elementos de tipo TColeccionGrupos es un lista doblemente encadenada de TGrupos, 
  con puntero al inicio y al final de la lista.

  Laboratorio de Programación 2. InCo-FIng-UDELAR
 */
#ifndef COLECCIONTGRUPOS_H
#define COLECCIONTGRUPOS_H

#include "grupoABB.h"

// Define el tipo TColeccionTGrupos como un puntero a rep_coleccionTGrupos
typedef struct rep_coleccionTGrupos *TColeccionTGrupos;

// Función para crear una nueva TColeccionTGrupos vacía
// Devuelve una colección vacía.
// La función es Theta(1) peor caso.
TColeccionTGrupos crearTColeccionTGruposVacia();

// Función para insertar ordenadamente un grupo en la lista de grupos según 
// la edad promedio (menor a mayor). Si ya existe uno o más grupos con la misma edad promedio,
// el nuevo grupo es agregado a continuación de estos.
// La función es O(n) peor caso, siendo n la cantidad de grupos en la colección
void insertarGrupoTColeccionTGrupos(TColeccionTGrupos coleccionTGrupos, TGrupoABB grupo);

// Función que elimina la lista con todos sus grupos. También libera
// la memoria de los visitantes.
// La función es O(n*m) peor caso, donde n es la cantidad de grupos en la colección y m  
// es la máxima cantidad de visitantes en el grupo más grande.
void liberarTColeccionTGrupos(TColeccionTGrupos &coleccionTGrupos);

// Función para imprimir secuencialmente los grupos de menor a mayor, según la edad promedio.
// La función es O(n*m) peor caso, donde n es la cantidad de grupos en la colección y m es la 
// máxima cantidad de visitantes en el grupo más grande.
// El formato de impresión es:
// Coleccion de grupos:
  //  <y luego para cada grupo se repite>
  // Grupo con edad promedio <edad promedio>:
  //  <imprimir el grupo con función imprimirTGrupoABB>

// Nota: la edad promedio se imprime con 2 dígitos después de la coma (formato '%.2f').
void imprimirTColeccionTGrupos(TColeccionTGrupos coleccionTGrupos);

// Función para imprimir secuencialmente los grupos de mayor a menor, según la edad promedio.
// La función es O(n*m) peor caso, donde n es la cantidad de grupos en la colección y m es la 
// máxima cantidad de visitantes en el grupo más grande.
// El formato de impresión es idéntico que en la función 'imprimirTColeccionTGrupos'
void imprimirInvertidoTColeccionTGrupos(TColeccionTGrupos coleccionTGrupos);

// Función quer retorna la cantidad de grupos en la colección.
// La función es O(n) peor caso, donde n es la cantidad de grupos en la colección
nat cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccionTGrupos);

// Función para obtener el primer grupo en la lista de grupos 
// La función es O(1) peor caso.
// PRE: la lista no es vacía
TGrupoABB obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccionTGrupos);

// Función para obtener un grupo en la lista de grupos. 'n' indica el índice desde el 
// inicio (base 1, invocar con n = 1 devuelve el primer elemento). 
// La función es O(n) peor caso, siendo n la cantidad de grupos en la lista.
// En caso de que n sea mayor que la cantidad de grupos en la lista retorna NULL
// PRE: n > 0
TGrupoABB obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccionTGrupos, int n);

// Función para eliminar el último grupo en la lista de grupos.
// Retorna el grupo removido.
// La función es O(1) en peor caso
// PRE: la lista no es vacía
TGrupoABB removerUltimoColeccionTGrupos(TColeccionTGrupos coleccionTGrupos);

// Función para eliminar el n-esimo grupo de la lista de grupos 'n' indica el índice desde el 
// inicio (base 1, invocar con n = 1 devuelve el primer elemento).
// Retorna el grupo removido.
// La función es O(n) en el peor caso, siendo n la cantidad de grupos en la lista.
// PRE: Hay al menos n elementos en la lista
// PRE: n > 0
TGrupoABB removerNesimoColeccionTGrupos(TColeccionTGrupos coleccionTGrupos, int n);

// Dada una coleccion de grupos, regresa el visitante que se encuentre en la mayor
// cantidad de grupos. Un visitante se considera repetido si su
// id es el mismo. Si todos los grupos de la colección están vacíos o si
// la colección de grupos es vacía, retorna NULL. Si hay varios visitantes empatados
// en apariciones, se retorna aquel con menor id.
// La función es O(n*n*m*m) peor caso, donde n es la cantidad de grupos en la colección y m es la 
// máxima cantidad de visitantes en el grupo más grande.
TVisitante visitanteMasRepetido(TColeccionTGrupos coleccionTGrupos);

// Dada una coleccion de grupos, regresa un nuevo grupo con aquellos visitantes que
// se encuentren en más de un grupo. Un visitante se considera repetido si su
// id es el mismo. Los integrantes del nuevo grupo son copias del 
// La función es O(n*n*m*m*m) peor caso, donde n es la cantidad de grupos en la colección y m es la 
// máxima cantidad de visitantes en el grupo más grande.
TGrupoABB obtenerVisitantesRepetidos(TColeccionTGrupos coleccionTGrupos);


#endif // COLECCIONTGRUPOS_H  

