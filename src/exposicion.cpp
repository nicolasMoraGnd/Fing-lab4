#include "../include/exposicion.h"

struct rep_exposicion{
    int id;
    TFecha inicio;
    TFecha fin;
    TConjuntoPiezas piezas;
};

TExposicion crearTExposicion(int idExp, TFecha ini, TFecha fin, int cantMax){ 
    TExposicion nuevaExposicion = new rep_exposicion;
    nuevaExposicion->id = idExp;
    nuevaExposicion->inicio = ini;
    nuevaExposicion->fin = fin;
    nuevaExposicion->piezas = crearTConjuntoPiezas(cantMax);

    return nuevaExposicion;
}

void agregarATExposicion(TExposicion &exp, TPieza p){
    if(exp != NULL){
        insertarTConjuntoPiezas(exp->piezas, idTPieza(p));
    }
    
}

bool perteneceATExposicion(TExposicion exp, TPieza p){ 
    if(exp != NULL){
        return perteneceTConjuntoPiezas(exp->piezas, idTPieza(p));
    }
    return false;
}

int idTExposicion(TExposicion exp){ return exp->id; }

void imprimirTExposicion(TExposicion exp){
    if(exp != NULL){
        printf("Exposicion #%d del ", exp->id);
        imprimirTFecha(exp->inicio);
        printf(" al ");
        imprimirTFecha(exp->fin);
        printf("\n");

        printf("Piezas: ");
        imprimirTConjuntoPiezas(exp->piezas);
    }
    
}

TFecha fechaInicioTExposicion(TExposicion exp){ return exp->inicio; }

TFecha fechaFinTExposicion(TExposicion exp){ return exp->fin; }

bool sonExposicionesCompatibles(TExposicion exp1, TExposicion exp2){ 
    bool comparten;

    //se comprueban los dos casos en los que no hay interseccion y se niega
    comparten = !( ((compararTFechas(exp1->inicio, exp2->inicio) > 0) &&  (compararTFechas(exp1->inicio, exp2->fin) > 0))
        || ((compararTFechas(exp2->inicio, exp1->inicio) > 0) && (compararTFechas(exp2->inicio, exp1->fin) > 0)));

    if(comparten){
        TConjuntoPiezas interseccion = interseccionTConjuntoPiezas(exp1->piezas, exp2->piezas);
        bool compatible = esVacioTConjuntoPiezas(interseccion);
        liberarTConjuntoPiezas(interseccion);
        return compatible;
    }else{
        return true;
    }

}

void liberarTExposicion(TExposicion &exp){
    liberarTFecha(exp->inicio);
    liberarTFecha(exp->fin);
    liberarTConjuntoPiezas(exp->piezas);
    delete exp;
    exp = NULL;
}



// Agregados tarea 4

TConjuntoPiezas obtenerPiezasTExposicion(TExposicion expo){
    return expo->piezas;
}
