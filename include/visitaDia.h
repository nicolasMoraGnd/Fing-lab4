/*
  Módulo de definición de 'TVisitaDia'.

  Los elementos de tipo TVisitaDia almacenan una coleccion de elementos de tipo TVisitante y una fecha.
  Representan los diferentes grupos que van llegando en un mismo día. Se implementa como una cola
  de prioridad.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef VISITADIA_H
#define VISITADIA_H
#include "grupoABB.h"
#include "pieza.h"

// Define el tipo TVisitaDia como un puntero a rep_visitadia
typedef struct rep_visitadia *TVisitaDia;

// Función para crear un elemento de tipo TVisitaDia.
// fecha es la fecha de la visita y N el id máximo que tendrá un grupo
// 0 < id <= N
// La función es O(N) peor caso.
TVisitaDia crearTVisitaDia(TFecha fecha, int N);

// Agrega un grupo a la visita según la prioridad dada por su edad promedio.
// La función es O(1) caso promedio y O(log(n)) peor caso.
// siendo n la cantidad máxima de grupos en la visita
void encolarGrupoTVisitaDia(TVisitaDia &visitaDia, TGrupoABB grupo);

// Devuelve la cantidad de grupos en la visita dia.
// La función es O(1) peor caso.
int cantidadGruposTVisitaDia(TVisitaDia visitaDia);

// Imprime la visita dia con el siguiente formato: 
//      Visita para dia: <fecha>
// Luego, la impresión se hace por niveles del árbol (heap), separando cada nivel 
// con un salto de línea y antecediéndolo con una línea que diga:
//      Nivel <i>
// Finalmente, para cada grupo en el nivel, se imprime:
//      <j>) Grupo <idGrupo> con edad promedio <edad promedio> 
//      <imprimirTGrupoABB>
// donde <j> es un iterador en la función, inicia en 1 y aumenta en 1 por cada grupo
// impreso.
// Se sugiere ver los test correspondientes si tiene
// dudas sobre el formato.
// Dada una cantidad máxima de visitantes por grupo fija la funcion es
// O(n), donde n es el máximo número de grupos en la visita dia
void imprimirTVisitaDia(TVisitaDia visitaDia);

// Retira el último grupo de la visita dia y lo regresa.
// Dada una cantidad máxima de visitantes por grupo fija La función es O(log(n)) peor caso.
// siendo n la cantidad máxima de grupos en la visita.
// PRE: cantidadVisitantesTVisitaDia > 0
TGrupoABB desencolarGrupoTVisitaDia(TVisitaDia &visitaDia);

// Función que libera la memoria asignada para la visita dia.
// Deja el puntero visitaDia apuntando a NULL.
// Ejecuta en O(n) peor caso, donde n es la cantidad de grupos 
// en la visitaDia.
void liberarTVisitaDia(TVisitaDia &visitaDia);

// Función que invierte la prioridad dada por la edad. 
// Si el grupo prioritario era el que tenía menor edad promedio pasa a ser el de
// mayor edad promedio y viceversa. Dada una cantidad máxima de visitantes por grupo fija 
// la función es O(n * log(n)) peor caso siendo N la cantidad máxima de grupos en la visita
void invertirPrioridadTVisitaDia(TVisitaDia &visita);

// Función que devuelve true si el grupo con id 'idGrupo' está en la visita y false en caso contrario.
// Esta función debe ser O(1) en peor caso
bool estaEnTVisitaDia(TVisitaDia visita, int idGrupo);

// Función que devuelve la prioridad del grupo con id 'idGrupo' en la visita.
// La función debe ser O(1) peor caso
// PRE: estaEnTVisitaDia(visita, idGrupo)
float prioridadTVisitaDia(TVisitaDia visita, int idGrupo);

// Función que devuelve el elemento más prioritario de la visitaDia.
// La función ejecuta en O(1) peor caso
// PRE: cantidadVisitantesTVisitaDia > 0
TGrupoABB masPrioritarioTVisitaDia(TVisitaDia visita);

// Función que devuelve la cantidad máximad de grupos en la visitaDia.
// La función ejecuta en O(1) peor caso
int maxGruposTVisitaDia(TVisitaDia visita);

// Devuelve la fecha de la visitaDia
// La función ejecuta en O(1) peor caso
TFecha fechaTVisitaDia(TVisitaDia visitaDia);

#endif // VISITADIA_H  










