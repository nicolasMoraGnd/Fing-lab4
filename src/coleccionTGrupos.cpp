#include "../include/coleccionTGrupos.h"


struct rep_nodo{
	TGrupoABB grupo;
	rep_nodo* anterior;
	rep_nodo* siguiente;
};

typedef rep_nodo *nodo;

struct rep_coleccionTGrupos {
	nodo primero;
	nodo ultimo;
};

TColeccionTGrupos crearTColeccionTGruposVacia(){
	TColeccionTGrupos nuevo;
	nuevo = new rep_coleccionTGrupos;

	nuevo->primero = NULL;
	nuevo->ultimo = NULL;
	return nuevo;
}

void insertarGrupoTColeccionTGrupos(TColeccionTGrupos coleccion, TGrupoABB grupo){
	nodo nuevo = new rep_nodo;
	nuevo->grupo = grupo;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

	if (coleccion->primero == NULL){
		coleccion->primero = nuevo;
		coleccion->ultimo = nuevo;
	}else{
		float edad = edadPromedioTGrupoABB(grupo);
		nodo actual = coleccion->primero;
		while (actual->siguiente != NULL && edad >= edadPromedioTGrupoABB(actual->grupo)){
			actual = actual->siguiente;
		}

		if (actual->siguiente == NULL && edad >= edadPromedioTGrupoABB(actual->grupo)){
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
            coleccion->ultimo = nuevo;
        } else if (actual->anterior == NULL) {
            nuevo->siguiente = actual;
            actual->anterior = nuevo;
            coleccion->primero = nuevo;			
		} else {
            nuevo->siguiente = actual;
            nuevo->anterior = actual->anterior;
            actual->anterior->siguiente = nuevo;
            actual->anterior = nuevo;
        }
	} 
}

void imprimirTColeccionTGrupos(TColeccionTGrupos coleccion){
	printf("Coleccion de grupos:\n");
	nodo actual = coleccion->primero;
	while (actual != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTGrupoABB(actual->grupo));
		imprimirTGrupoABB(actual->grupo);
		actual = actual->siguiente;
	}
}

void imprimirInvertidoTColeccionTGrupos(TColeccionTGrupos coleccion){
	printf("Coleccion de grupos:\n");
	nodo actual = coleccion->ultimo;
	while (actual != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTGrupoABB(actual->grupo));
		imprimirTGrupoABB(actual->grupo);
		actual = actual->anterior;
	}	
}

nat cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccion){
	nat cant = 0;
	nodo actual = coleccion->ultimo;
	while (actual != NULL){
		cant++;
		actual = actual->anterior;
	}	
	return cant;
}

TGrupoABB obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	nodo actual = coleccion->primero;
	if (actual == NULL) return NULL;

	while (actual->siguiente != NULL && n > 1){
		actual = actual->siguiente;
		n--;
	}
	return actual->grupo;
}

TGrupoABB obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccion){
	return coleccion->primero->grupo;
}

TGrupoABB removerUltimoColeccionTGrupos(TColeccionTGrupos coleccion){
	TGrupoABB grupo = coleccion->ultimo->grupo;
	nodo temp = coleccion->ultimo;
	if (coleccion->ultimo == coleccion->primero){
		coleccion->primero = NULL;
		coleccion->ultimo = NULL;
	}else{
		coleccion->ultimo->anterior->siguiente = NULL;
		coleccion->ultimo = coleccion->ultimo->anterior;		
	}
	delete temp;
	return grupo;
}

TGrupoABB removerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	nodo actual = coleccion->primero;
	while (actual->siguiente != NULL && n > 1){
		actual = actual->siguiente;
		n--;
	}
	TGrupoABB grupo = actual->grupo;
	// Es el primero
	if (actual->anterior == NULL) {
		coleccion->primero = actual->siguiente;
		if (coleccion->primero == NULL) {
			coleccion->ultimo = NULL;
		}else{
			coleccion->primero->anterior = NULL;
		}
	} else if (actual->siguiente == NULL) {
		coleccion->ultimo = actual->anterior;
		if (coleccion->ultimo == NULL) {
			coleccion->primero = NULL;
		} else {
			coleccion->ultimo->siguiente = NULL;
		}
	} else {
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
	}
	delete actual;
	return grupo;

}

void liberarTColeccionTGrupos(TColeccionTGrupos &coleccion){
	nodo actual = coleccion->primero;
	while (actual != NULL){
		liberarTGrupoABB(actual->grupo);
		nodo temp = actual;
		actual = actual->siguiente;
		delete temp;
	}
	delete coleccion;
	coleccion = NULL;
}

TGrupoABB obtenerVisitantesRepetidos(TColeccionTGrupos coleccion){
	TGrupoABB resultado = crearTGrupoABBVacio(-1);
	
	nodo actual = coleccion->primero;
	while (actual != NULL){
		TGrupoABB grupoActual = actual->grupo;
		int cantGrupoActual = cantidadVisitantesTGrupoABB(grupoActual);

		for (int i = 0; i < cantGrupoActual; i++){
			TVisitante visitante = obtenerNesimoVisitanteTGrupoABB(grupoActual, i + 1);
			// si el visitante ya está en el grupo resultado no sigo buscando
			if (!existeTVisitanteTGrupoABB(resultado, idTVisitante(visitante))){
				nodo iterBusqueda = actual->siguiente;
				bool encontreRepetido = false;
				while (iterBusqueda != NULL && !encontreRepetido){
					TGrupoABB siguienteGrupo = iterBusqueda->grupo;

					if (existeTVisitanteTGrupoABB(siguienteGrupo, idTVisitante(visitante))){
						encontreRepetido = true;
					}
					iterBusqueda = iterBusqueda->siguiente;
				}

				if (encontreRepetido){
					insertarTVisitanteTGrupoABB(resultado, copiarTVisitante(visitante));
				}
			}
		}

		actual = actual->siguiente;
	}

	return resultado;
}

TVisitante visitanteMasRepetido(TColeccionTGrupos coleccion){
	int cantMaxRepetido = 0;
	TVisitante masRepetido = NULL;

	nodo actual = coleccion->primero;
	while (actual != NULL){
		TGrupoABB grupoActual = actual->grupo;
		int cantGrupoActual = cantidadVisitantesTGrupoABB(grupoActual);

		for (int i = 0; i < cantGrupoActual; i++){
			TVisitante visitante = obtenerNesimoVisitanteTGrupoABB(grupoActual, i + 1);

			int cantRepeticiones = 0;
			if (masRepetido == NULL || idTVisitante(visitante) != idTVisitante(masRepetido)) {
				cantRepeticiones++;

				nodo iterBusqueda = actual->siguiente;
				while (iterBusqueda != NULL){
					TGrupoABB siguienteGrupo = iterBusqueda->grupo;

					if (existeTVisitanteTGrupoABB(siguienteGrupo, idTVisitante(visitante))){
						cantRepeticiones++;
					}
					iterBusqueda = iterBusqueda->siguiente;
				}

				if (cantRepeticiones > cantMaxRepetido ||
					(cantRepeticiones == cantMaxRepetido && idTVisitante(visitante) < idTVisitante(masRepetido))
					){
					masRepetido = visitante;
					cantMaxRepetido = cantRepeticiones;
				}
			}
		}

		actual = actual->siguiente;
	}

	return masRepetido;
}
