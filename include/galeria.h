/*
  Módulo de definición de 'TGaleria'.

  Los elementos de tipo TGaleria contiene las estructuras necesarias para manejar la galeria.
  Un tipo Galeria tiene:
    - Una ColeccionPiezas con las piezas de la galeria
    - Una Fecha que representa la fecha actual.
    - Una lista de exposiciones finalizadas.
    - Una lista de exposiciones activas.
    - Una lista de exposiciones futuras.

    - Una instancia de visitaDia para manejar los grupos que van llegando a la galería.
    - Una instancia de hashVisitaDia para manejar las visitasDia históricas.
    
  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef GALERIA_H
#define GALERIA_H
#include "coleccionPiezas.h"
#include "listaExposiciones.h"
#include "hashVisitaDia.h"

#define MAX_GRUPOS_VISITA_DIA 100
#define CANT_ESTIMADA_VISITA_DIA_PASADAS 100

typedef struct rep_galeria* TGaleria;

// Crea una galeria sin piezas ni exposiciones, con la fecha marcada por parámetro.
TGaleria crearTGaleria(TFecha fecha);

// Agrega la pieza a la galeria. La pieza hasta el momento no 
// Ejecuta en O(n) peor caso, donde ne es la cantidad de piezas de la galeria.
// PRE: no existe una pieza con mismo id en la galeria.
void agregarPiezaTGaleria(TGaleria galeria, TPieza pieza);

// Agrega la exposición a la galería.
// PRE: esCompatibleExposicionGaleria
void agregarExposicionTGaleria(TGaleria galeria, TExposicion expo);

// Agrega la pieza de id 'idPieza' a la exposición con id 'idExpo'
// PRE: existen una pieza en la galeria con id 'idPieza'
// PRE: existe una exposición en la galeria con id 'idExpo'
void agregarPiezaAExposicionTGaleria(TGaleria galeria, int idPieza, int idExpo);

// Imprime las exposiciones finalizadas.
// La función es O(n) donde n es el número de exposiciones finalizadas.
void imprimirExposicionesFinalizadasTGaleria(TGaleria galeria);

// Imprime las exposiciones activas.
// La función es O(n) donde n es el número de exposiciones activas.
void imprimirExposicionesActivasTGaleria(TGaleria galeria);

// Imprime las exposiciones futuras.
// La función es O(n) donde n es el número de exposiciones futuras.
void imprimirExposicionesFuturasTGaleria(TGaleria galeria);

// Devuelve true si la exposicion 'expo' es compatible con el resto de las exposiciones de la galeria
bool esCompatibleExposicionTGaleria(TGaleria galeria, TExposicion expo);


// Funciones con agregados tarea 4

// Crea una galeria sin piezas ni exposiciones, con la fecha marcada por parámetro.
// Nuevo: inicializa la visitaDia
TGaleria crearTGaleria(TFecha fecha);

// Realiza la modificación lógica de la fecha. Modifica la fecha
// de la galería y las listas de exposiciones para reflejar cuáles están finalizadas, 
// cuáles activas y cuáles siguen siendo futuras.
// Nuevo: libera la memoria asociada a la visitaDía actual y agrega la visitaDia
// al histórico.
// PRE: la fecha parámetro es posterior a la fecha actual de la galeria
void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha);

// Libera la memoria utilizada por la galeria
// También libera la memoria de todas las piezas y exposiciones en la galeria.
// Nuevo: libera la memoria asociada a la visitaDía y al histórico de visitasDia.
void liberarTGaleria(TGaleria &galeria);


// Funciones tarea 4

// Calcula el índice de felicidad de un visitante de la galería, definido de la siguiente
// forma:
// Sea cpf la cantidad de piezas favoritas del visitante.
// Sea cpfe la cantidad de piezas favoritas del visitante que se encuentran actualmente
// en exposicion.
// El índice de felicidad se define como cpfe / cpf.
// Si el visitante no tiene piezas favoritas, devuelve 1.
float indiceFelicidadVisitanteTGaleria(TGaleria galeria, TVisitante visitante);

// Registra la llegada de un nuevo grupo a la galería. Lo almacena en la visitaDia
// La función es O(1) caso promedio y O(log(n)) peor caso.
void llegaGrupoTGaleria(TGaleria galeria, TGrupoABB grupoABB);

// Dada la fecha actual de la galería, devuelve una colección piezas
// indicando aquellas piezas que se encuentran en exposición (es decir, que 
// están incluídas en alguna exposición activa)
TConjuntoPiezas piezasEnExposicionTGaleria(TGaleria galeria);

// Dada la fecha actual de la galería, devuelve una colección piezas
// indicando aquellas piezas que no están en exposición.
TConjuntoPiezas piezasEnReservaTGaleria(TGaleria galeria);

// Devuelve la instancia de visita dia de la galería para la fecha 
// indicada por parámetro.
// PRE: la fecha es anterior o igual a la fecha actual.
TVisitaDia obtenerVisitaDiaTGaleria(TGaleria galeria, TFecha fecha);

#endif  // EXPOSICION_H