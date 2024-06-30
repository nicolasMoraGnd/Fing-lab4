#include "../include/conjuntoPiezas.h"
struct rep_conjuntopiezas{
    int cantidad;
    bool * elementos;
    int cantMax;
};

TConjuntoPiezas crearTConjuntoPiezas(int cantMax){ 
    TConjuntoPiezas nuevoConjunto = new rep_conjuntopiezas;
    nuevoConjunto->elementos = new bool[cantMax];
    nuevoConjunto->cantidad = 0;
    nuevoConjunto->cantMax =cantMax;
    
    for(int i = 0; i < cantMax; i++ ){
        nuevoConjunto->elementos[i] = false;
    }
    
    return nuevoConjunto;
}

bool esVacioTConjuntoPiezas(TConjuntoPiezas c){ return c->cantidad == 0; }

void insertarTConjuntoPiezas(TConjuntoPiezas &c, int id){
    if(id < c->cantMax && !c->elementos[id]){
        c->elementos[id] = true;
        c->cantidad++;
    }
}

void borrarDeTConjuntoPiezas(TConjuntoPiezas &c, int id){
    if(id < c->cantMax && c->elementos[id]){
        c->elementos[id] = false;
        c->cantidad--;
    }
}

bool perteneceTConjuntoPiezas(TConjuntoPiezas c, int id){ 
    return (id < c->cantMax && c->elementos[id]);
}

int cardinalTConjuntoPiezas(TConjuntoPiezas c){ return c->cantidad; }

int cantMaxTConjuntoPiezas(TConjuntoPiezas c){ return c->cantMax; }

void imprimirTConjuntoPiezas(TConjuntoPiezas c){
    for(int i = 0; i < c->cantMax; i++ ){
        if(c->elementos[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

void liberarTConjuntoPiezas(TConjuntoPiezas &c){
    delete [] c->elementos;
    delete c;
    c = NULL;
}

TConjuntoPiezas unionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){ 
    if (c1 == NULL)
    {
        TConjuntoPiezas cUnion = crearTConjuntoPiezas(c2->cantMax);
        for(int i = 0; i < c2->cantMax; i++ ){
            if(c2->elementos[i]){
                cUnion->elementos[i] = true;
                cUnion->cantidad++;
            }
        }
        return cUnion;

    }else if(c2 == NULL){
        TConjuntoPiezas cUnion = crearTConjuntoPiezas(c1->cantMax);
        for(int i = 0; i < c1->cantMax; i++ ){
            if(c1->elementos[i]){
                cUnion->elementos[i] = true;
                cUnion->cantidad++;
            }
        }
        return cUnion;
    }
    
    TConjuntoPiezas cUnion = crearTConjuntoPiezas(c1->cantMax);
    for(int i = 0; i < c1->cantMax; i++ ){
        if(c1->elementos[i] || c2->elementos[i]){
            cUnion->elementos[i] = true;
            cUnion->cantidad++;
        }
    }
    
    return cUnion; 
}

TConjuntoPiezas interseccionTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){
    if (c1 == NULL || c2 == NULL){
        return NULL;
    }
    TConjuntoPiezas cInter = crearTConjuntoPiezas(c1->cantMax);
    for(int i = 0; i < c1->cantMax; i++ ){
        if(c1->elementos[i] && c2->elementos[i]){
            cInter->elementos[i] = true;
            cInter->cantidad++;
        }
    }
    
    return cInter; 
}

TConjuntoPiezas diferenciaTConjuntoPiezas(TConjuntoPiezas c1, TConjuntoPiezas c2){
    TConjuntoPiezas cDif = crearTConjuntoPiezas(c1->cantMax);
    for(int i = 0; i < c1->cantMax; i++ ){
        if(c1->elementos[i] && !c2->elementos[i]){
            cDif->elementos[i] = true;
            cDif->cantidad++;
        }
    }
    
    return cDif;
}
