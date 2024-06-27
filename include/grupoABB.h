/*
  Módulo de definición de 'TGrupoABB'.

  Los elementos de tipo TGrupoABB almacenan una coleccion de elementos de tipo TVisitante.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef GRUPOABB_H
#define GRUPOABB_H

#include "visitante.h"

// Define el tipo TGrupoABB como un puntero a rep_grupo.
typedef struct rep_grupoABB *TGrupoABB;

// Función para crear un nuevo grupo vacío.
// Devuelve un nuevo árbol binario vacío.
// La funcion es Theta(1) peor caso.
TGrupoABB crearTGrupoABBVacio(int id);


// Funcion que retorna la id del grupo.
// La función es Theta(1) en el peor caso
int idGrupo(TGrupoABB grupoABB);


// Funcion que retorna true si el grupo es vacio y false en el caso contrario.
// La función es O(1) en el peor caso
bool esVacioGrupo(TGrupoABB grupoABB);

// Función para insertar un visitante en el árbol binario, por id.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo.
// PRE: El visitante no está en el grupo.
void insertarTVisitanteTGrupoABB(TGrupoABB &grupoABB, TVisitante visitante);

// Función para imprimir los visitantes del grupo en orden de id. La impresión
// de los visitantes se realiza con la función 'imprimirTVisitante'.
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
void imprimirTGrupoABB(TGrupoABB grupoABB);

// Función para liberar la memoria asignada a un grupo.
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
void liberarTGrupoABB(TGrupoABB &grupoABB);

// Función que determina si un visitante está en el árbol binario.
// Devuelve true si el visitante está en el grupo, false en caso contrario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de visitantes en el grupo.
bool existeTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante);

// Función para obtener un visitante del árbol binario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de visitantes en el grupo
// PRE: el visitante está en el grupo
TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante);

// Funcion para obtener la altura del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo
nat alturaTGrupoABB(TGrupoABB grupoABB);

// Función para obtener el visitante con el id más grande del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el árbol binario
// PRE: el árbol binario no es vacío
TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB);

// Función para eliminar un visitante del árbol binario.
// En caso de que el nodo a remover tenga ambos subárboles no vacíos, se
// reemplaza por el visitante con el id más grande del subárbol izquierdo. 
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
// PRE: El visitante está en el grupo
void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante);

// Función para obtener la cantidad de visitantes en el árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo
int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB);

// Funcion para obtener la edad promedio de los visitantes. Si no hay visitantes en el grupo devuelve 0.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo.
float edadPromedioTGrupoABB(TGrupoABB grupoABB);

// Función para obtener el Nesimo visitante del grupo. El órden de los visitantes
// se considera por orden de 'id', con base 1.
// Ejemplos:  
//  obtenerNesimoVisitanteTGrupoABB(grupo, 1) devuelve el visitante con menor id
//  obtenerNesimoVisitanteTGrupoABB(grupo, 2) devuelve el segundo visitante con menor id
//  obtenerNesimoVisitanteTGrupoABB(grupo, cantidadVisitantesTGrupoABB(grupo)) devuelve el 
//  visitante con mayor id.
// La funcion es Theta(m) peor caso, siendo m la cantidad de visitantes en el grupo.
// PRE: cantidadVisitantesTGrupoABB(grupo) >= n
// PRE: n > 0 
TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n);

#endif // GRUPOABB_H  

