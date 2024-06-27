#include "../include/pieza.h"

// Estructura para almacenar una fecha con día, mes y año
struct rep_pieza {
    int identificador;
    char nombrePieza[MAX_NOMBRE_PIEZA];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR]; 
    TFecha fechaCreacion;
};

// Función que crea un elemento de tipo TPieza con los valores dados
TPieza crearTPieza(int identificador, const char nombrePieza[MAX_NOMBRE_PIEZA], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], TFecha fechaCreacion){
    TPieza nuevaPieza = new rep_pieza;
    nuevaPieza->identificador = identificador;
    strcpy(nuevaPieza->nombrePieza, nombrePieza);
    strcpy(nuevaPieza->nombreAutor, nombreAutor);
    strcpy(nuevaPieza->apellidoAutor, apellidoAutor);
    nuevaPieza->fechaCreacion = fechaCreacion;
    return nuevaPieza;
}

int idTPieza(TPieza pieza){ 
    return pieza->identificador; 
}

void imprimirTPieza(TPieza pieza){
    printf("Pieza: %i\n", pieza->identificador);
    printf("%s-%s %s\n", pieza->nombrePieza, pieza->nombreAutor, pieza->apellidoAutor);
    printf("Creada en: ");
    imprimirTFecha(pieza->fechaCreacion);
}

void liberarTPieza(TPieza &pieza){
    liberarTFecha(pieza->fechaCreacion);
    delete pieza;
    pieza = NULL;
}


