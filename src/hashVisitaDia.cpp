
#include "../include/hashVisitaDia.h"

struct rep_hashvisitadia {
};

// interna funcion hash
int funcionHash(TFecha fecha, int cantEstimadas){
    return (31 * (int) mesTFecha(fecha) + (int) diaTFecha(fecha)) % cantEstimadas;
}

THashVisitaDia crearTHashVisitaDia(int cantEstimadas){
    return NULL;
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

void liberarTHashVisitaDia(THashVisitaDia &hash){
}
