
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
    int posicion = funcionHash(fechaTVisitaDia(visitaDia), hash->cantEstimada);
    nodoHash posicionHash = hash->nodos[posicion];
    
    nodoHash nodoIns = new rep_nodoHash;
    nodoIns->visita = visitaDia;
    nodoIns->sig = NULL;

    if (posicionHash == NULL)
    {
        hash->nodos[posicion] = nodoIns;
    }else{
        nodoIns->sig = posicionHash;
        hash->nodos[posicion] = nodoIns;
    }
}

void imprimirTHashVisitaDia(THashVisitaDia hash){
    for (int i = 0; i < hash->cantEstimada; i++)
    {
        if (hash->nodos[i] != NULL)
        {
            printf("Elementos en la posicion %d de la tabla:\n", i);
            nodoHash aux = hash->nodos[i];
            while (aux != NULL)
            {
                imprimirTVisitaDia(aux->visita);
                aux = aux->sig;
            }
            
        }else{
            printf("No hay elementos guardados la posicion %d de la tabla.\n", i);
        }
        
    }
    
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
