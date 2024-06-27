#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TColeccionPiezas sig;
    TPieza pieza;
};

TColeccionPiezas crearColeccionPiezasVacia(){ 
    return NULL; 
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    int idPieza = idTPieza(pieza);
    TColeccionPiezas nuevoElemento = new rep_coleccionpiezas;
    nuevoElemento->pieza = pieza;
    nuevoElemento->sig = NULL;

    if ((esVaciaColeccionPiezas(coleccionPiezas)) || (idPieza < idTPieza(coleccionPiezas->pieza))){
        nuevoElemento->sig = coleccionPiezas;
        coleccionPiezas = nuevoElemento;
    }else{
        TColeccionPiezas iter = coleccionPiezas;
        while (iter->sig != NULL && idPieza > idTPieza(iter->sig->pieza)){
            iter = iter->sig;
        }
        nuevoElemento->sig = iter->sig;
        iter->sig = nuevoElemento;
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    TColeccionPiezas iter = coleccionPiezas;
    while (iter != NULL){
        imprimirTPieza(iter->pieza);
        iter = iter->sig;
    }
}

bool esVaciaColeccionPiezas(TColeccionPiezas piezas){
    return piezas == NULL;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    bool res = false;
    TColeccionPiezas iter = coleccionPiezas;
    while (iter != NULL && !res){
        if (idPieza == idTPieza(iter->pieza)){
            res = true;
        }
        iter = iter->sig;
    }
    return res;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    TPieza res = NULL;
    TColeccionPiezas iter = coleccionPiezas;
    while (iter != NULL && !res) {
        if (idPieza == idTPieza(iter->pieza)) {
            res = iter->pieza;
        }
        iter = iter->sig;
    }
    return res;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    if (coleccionPiezas != NULL){
        if (idTPieza(coleccionPiezas->pieza) == idPieza){
            TColeccionPiezas aBorrar = coleccionPiezas;
            coleccionPiezas = coleccionPiezas->sig;
            liberarTPieza(aBorrar->pieza);
            delete aBorrar;
        }else{
            TColeccionPiezas iter = coleccionPiezas;
            while (iter->sig != NULL && idTPieza(iter->sig->pieza) != idPieza){
                iter = iter->sig;
            }
            if (iter->sig != NULL){
                TColeccionPiezas aBorrar = iter->sig;
                liberarTPieza(aBorrar->pieza);
                iter->sig = aBorrar->sig;
                delete aBorrar;
            }
        }
    }
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    while (coleccionPiezas != NULL){
        TColeccionPiezas aux = coleccionPiezas;
        coleccionPiezas = coleccionPiezas->sig;
        liberarTPieza(aux->pieza);
        delete aux;
    }
}