
#include "../include/hashVisitaDia.h"
typedef struct rep_nodoHash *nodoHash;

struct rep_nodoHash {
    TVisitaDia visita;
    nodoHash sig;
};



struct rep_hashvisitadia {
    int cantEstimada;
    int cantidad;
    nodoHash* nodos;
};

// interna funcion hash
int funcionHash(TFecha fecha, int cantEstimadas){
    return (31 * (int) mesTFecha(fecha) + (int) diaTFecha(fecha)) % cantEstimadas;
}

THashVisitaDia crearTHashVisitaDia(int cantEstimadas){
    THashVisitaDia nuevoHash = new rep_hashvisitadia;
    nuevoHash->nodos = new nodoHash[cantEstimadas];
    nuevoHash->cantidad = 0;
    nuevoHash->cantEstimada = cantEstimadas;

    for (int i = 0; i < cantEstimadas; i++)
    {
        nuevoHash->nodos[i] = NULL;
    }
    
    return nuevoHash;
}

void agregarVisitaDiaTHashVisitaDia(THashVisitaDia hash, TVisitaDia visitaDia){
}

void imprimirTHashVisitaDia(THashVisitaDia hash){
}

TVisitaDia obtenerVisitaDiaTHashVisitaDia(THashVisitaDia hash, TFecha fecha){
    return NULL;
}

bool perteneceVisitaDiaTHashVisitaDia(THashVisitaDia hash, TFecha fecha){
    return false;
}

void liberarNodoHash(nodoHash listaNodos){
    if (listaNodos != NULL){
        liberarNodoHash(listaNodos->sig);
        liberarTVisitaDia(listaNodos->visita);
        delete listaNodos;
        listaNodos = NULL;
    }    
}

void liberarTHashVisitaDia(THashVisitaDia &hash){
    for (int i = 0; i < hash->cantEstimada; i++)
    {
        liberarNodoHash(hash->nodos[i]);

    }
    delete [] hash->nodos;
    delete hash;
    hash = NULL;
}
