#include "../include/grupoABB.h"

struct arbol{
    TVisitante visitante;
    arbol* izq;
    arbol* der;   
};

struct rep_grupoABB {
    arbol* arb;
    int idGrupo;
};

typedef struct arbol* TArbol;

void insertarTVisitanteTArbol(TArbol &grupoABB, TVisitante visitante){
    if (grupoABB == NULL) {
        grupoABB = new arbol;
        grupoABB->visitante = visitante;
        grupoABB->izq = NULL;
        grupoABB->der = NULL;
    } else {
        if (idTVisitante(visitante) < idTVisitante(grupoABB->visitante)) {
            insertarTVisitanteTArbol(grupoABB->izq, visitante);
        } else {
            insertarTVisitanteTArbol(grupoABB->der, visitante);
        }
    }
}

TVisitante maxIdTVisitanteTArbol(TArbol grupoABB){
    if (grupoABB->der == NULL) {
        return grupoABB->visitante;
    } else {
        return maxIdTVisitanteTArbol(grupoABB->der);
    }
}

void imprimirTArbol(TArbol grupoABB){
    if (grupoABB != NULL) {
        imprimirTArbol(grupoABB->izq);
        imprimirTVisitante(grupoABB->visitante);
        imprimirTArbol(grupoABB->der);
    }
}

bool existeTVisitanteTArbol(TArbol grupoABB, int idVisitante){
    if (grupoABB == NULL) {
        return false;
    } else {
        if (idVisitante < idTVisitante(grupoABB->visitante)) {
            return existeTVisitanteTArbol(grupoABB->izq, idVisitante);
        } else if (idVisitante > idTVisitante(grupoABB->visitante)) {
            return existeTVisitanteTArbol(grupoABB->der, idVisitante);
        } else {
            return true;
        }
    }
}

TVisitante obtenerTVisitanteTArbol(TArbol grupoABB, int idVisitante){
    if (idVisitante < idTVisitante(grupoABB->visitante)) {
        return obtenerTVisitanteTArbol(grupoABB->izq, idVisitante);
    } if (idVisitante > idTVisitante(grupoABB->visitante)) {
        return obtenerTVisitanteTArbol(grupoABB->der, idVisitante);
    } else {
        return grupoABB->visitante;
    }
}

// función auxiliar para liberar un nodo
void liberarNodoTArbol(TArbol &grupoABB) {
    liberarTVisitante(grupoABB->visitante);
    delete grupoABB;
    grupoABB = NULL;
}

void removerTVisitanteTArbol(TArbol &grupoABB, int idVisitante){
    if (grupoABB != NULL) {
        if (idVisitante < idTVisitante(grupoABB->visitante)) {
            removerTVisitanteTArbol(grupoABB->izq, idVisitante);
        } else if (idVisitante > idTVisitante(grupoABB->visitante)) {
            removerTVisitanteTArbol(grupoABB->der, idVisitante);
        } else if (grupoABB->izq == NULL && grupoABB->der == NULL) {
            liberarNodoTArbol(grupoABB);
        } else {
            if (grupoABB->izq == NULL) {
                TArbol aux = grupoABB;
                grupoABB = grupoABB->der;
                liberarNodoTArbol(aux);
            } else if (grupoABB->der == NULL) {
                TArbol aux = grupoABB;
                grupoABB = grupoABB->izq;
                liberarNodoTArbol(aux);
            } else {
                liberarTVisitante(grupoABB->visitante);
                grupoABB->visitante = copiarTVisitante(maxIdTVisitanteTArbol(grupoABB->izq));
                removerTVisitanteTArbol(grupoABB->izq, idTVisitante(grupoABB->visitante));
            }
        }
    }
}

nat alturaTArbol(TArbol grupoABB) {
    if (grupoABB == NULL) {
        return 0;
    } else {
        nat alturaIzq = alturaTArbol(grupoABB->izq);
        nat alturaDer = alturaTArbol(grupoABB->der);
        if (alturaIzq > alturaDer) {
            return 1 + alturaIzq;
        } else {
            return 1 + alturaDer;
        }
    }
}

int cantidadVisitantesTArbol(TArbol grupoABB){
    if (grupoABB == NULL) {
        return 0;
    } else {
        int cantVisitantesIzq = cantidadVisitantesTArbol(grupoABB->izq);
        int cantVisitantesDer = cantidadVisitantesTArbol(grupoABB->der);
        return 1 + cantVisitantesIzq + cantVisitantesDer;
    }
}

int edadTotalVisitantesTArbol(TArbol grupoABB){
    if (grupoABB == NULL) {
        return 0;
    } else {
        int edadTotalIzq = edadTotalVisitantesTArbol(grupoABB->izq);
        int edadTotalDer = edadTotalVisitantesTArbol(grupoABB->der);
        return edadTVisitante(grupoABB->visitante) + edadTotalIzq + edadTotalDer;
    }
}

float edadPromedioTArbol(TArbol grupoABB) {
    int cantidadVisitantes = cantidadVisitantesTArbol(grupoABB);
    if (cantidadVisitantes == 0){
        return 0;
    }else{
        int edadTotal = edadTotalVisitantesTArbol(grupoABB);
        return edadTotal / ((float) cantidadVisitantes);
    }
}

void liberarTArbol(TArbol &grupoABB){
    if (grupoABB != NULL) {
        liberarTArbol(grupoABB->izq);
        liberarTArbol(grupoABB->der);
        liberarNodoTArbol(grupoABB);
    }
}

TVisitante obtenerNesimoVisitanteTArbol(TArbol grupoABB, int n){
    int cantIzq = cantidadVisitantesTArbol(grupoABB->izq);
    if (cantIzq >= n) {
        return obtenerNesimoVisitanteTArbol(grupoABB->izq, n);
    } else if (n == cantIzq + 1){
        return grupoABB->visitante;
    } else {
        return obtenerNesimoVisitanteTArbol(grupoABB->der, n - cantIzq - 1);
    }
}




//------------------------------------
// Nuevas implementaciones wrapper

TGrupoABB crearTGrupoABBVacio(int idGrupo){
    TGrupoABB nuevo = new rep_grupoABB;
    nuevo->idGrupo = idGrupo;
    nuevo->arb = NULL;
    return nuevo;
}

int idGrupo(TGrupoABB grupo){
    return grupo->idGrupo;
}

bool esVacioGrupo(TGrupoABB grupoABB){
    return grupoABB->arb == NULL;
}

void insertarTVisitanteTGrupoABB(TGrupoABB &grupoABB, TVisitante visitante){
    insertarTVisitanteTArbol(grupoABB->arb, visitante);
}


// Función para imprimir los visitantes del grupo en orden de id. La impresión
// de los visitantes se realiza con la función 'imprimirTVisitante'.
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
void imprimirTGrupoABB(TGrupoABB grupoABB){
    imprimirTArbol(grupoABB->arb);
}

// Función para liberar la memoria asignada a un grupo.
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
void liberarTGrupoABB(TGrupoABB &grupoABB){
    liberarTArbol(grupoABB->arb);
    delete grupoABB;
}

// Función que determina si un visitante está en el árbol binario.
// Devuelve true si el visitante está en el grupo, false en caso contrario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de visitantes en el grupo.
bool existeTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    return existeTVisitanteTArbol(grupoABB->arb, idVisitante);

}

// Función para obtener un visitante del árbol binario.
// La funcion es O(log(n)) caso promedio, siendo n la cantidad de visitantes en el grupo
// PRE: el visitante está en el grupo
TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    return obtenerTVisitanteTArbol(grupoABB->arb, idVisitante);
}

// Funcion para obtener la altura del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo
nat alturaTGrupoABB(TGrupoABB grupoABB){
    return alturaTArbol(grupoABB->arb);
}

// Función para obtener el visitante con el id más grande del árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el árbol binario
// PRE: el árbol binario no es vacío
TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB){
    return maxIdTVisitanteTArbol(grupoABB->arb);
}

// Función para eliminar un visitante del árbol binario.
// En caso de que el nodo a remover tenga ambos subárboles no vacíos, se
// reemplaza por el visitante con el id más grande del subárbol izquierdo. 
// La función es Theta(n) peor caso, donde n es la cantidad de visitantes en el grupo.
// PRE: El visitante está en el grupo
void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){
    removerTVisitanteTArbol(grupoABB->arb, idVisitante);
}

// Función para obtener la cantidad de visitantes en el árbol binario.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo
int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB){
    return cantidadVisitantesTArbol(grupoABB->arb);
}

// Funcion para obtener la edad promedio de los visitantes. Si no hay visitantes en el grupo devuelve 0.
// La funcion es Theta(n) peor caso, siendo n la cantidad de visitantes en el grupo.
float edadPromedioTGrupoABB(TGrupoABB grupoABB){
    return edadPromedioTArbol(grupoABB->arb);
}

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
TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    return obtenerTVisitanteTArbol(grupoABB->arb, n);
}
