#include "../include/visitante.h"


// Define la estructura visitante
struct rep_visitante {
    int id;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO]; 
    int edad;
    TConjuntoPiezas piezasFavoritas;
};

// Función que retorna el nombre de la visitante
void nombreTVisitante(TVisitante visitante, char nombre[MAX_NOMBRE]){
    strcpy(nombre, visitante->nombre);
}

// Funcion que retorna el apellido de la visitante
void apellidoTVisitante(TVisitante visitante, char apellido[MAX_APELLIDO]){
    strcpy(apellido,visitante->apellido);
}

// Función que retorna el id del visitante
int idTVisitante(TVisitante visitante){
    return visitante->id;
}

// Función que retorna la edad del visitante
int edadTVisitante(TVisitante visitante){
    return visitante->edad;
}


TVisitante copiarTVisitante(TVisitante visitante){
    return crearTVisitante(visitante->id, visitante->nombre, visitante->apellido, visitante->edad);
}

void imprimirTVisitante(TVisitante visitante){
    printf("Visitante %s %s\n", visitante->nombre, visitante->apellido);
    printf("Id: %i\n",visitante->id);
    printf("Edad: %i\n",visitante->edad);
}

// Agregados tarea 4


TVisitante crearTVisitante(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TVisitante nuevoVisitante = new rep_visitante;
    nuevoVisitante->id = id;
    nuevoVisitante->edad = edad;
    strcpy(nuevoVisitante->nombre, nombre);
    strcpy(nuevoVisitante->apellido, apellido);
    nuevoVisitante->piezasFavoritas = crearTConjuntoPiezas(MAX_PIEZAS);
    return nuevoVisitante;    
}


// Función que libera la memoria asignada para un visitante
void liberarTVisitante(TVisitante &visitante){
    liberarTConjuntoPiezas(visitante->piezasFavoritas);
    delete visitante;
    visitante = NULL;
}


// Agrega una pieza a las piezas favoritas del visitante.
// Ejecuta en O(1) peor caso.
void agregarPiezaFavoritaTVisitante(TVisitante visitante, int idPieza){
    insertarTConjuntoPiezas(visitante->piezasFavoritas, idPieza);
}
 
// Devuelve la instancia de TConjuntoPiezas que indica las piezas
// favoritas del visitante.
// Ejecuta en O(1) peor caso.
TConjuntoPiezas obtenerPiezasFavoritasTVisitante(TVisitante visitante){
    return visitante->piezasFavoritas;
}


