#include "../include/listaExposiciones.h"

struct rep_listaexposiciones {
    TExposicion exposicion;
    TListaExposiciones sig;
};

TListaExposiciones crearTListaExposicionesVacia(){ 
    return NULL; 
}

void agregarExposicionTListaExposiciones(TListaExposiciones &listaExposiciones, TExposicion expo){
    TListaExposiciones nuevoNodo = new rep_listaexposiciones;
    nuevoNodo->sig = NULL;
    nuevoNodo->exposicion = expo;

    //no hay nada o es el primero
    if(listaExposiciones == NULL 
        || compararTFechas(fechaInicioTExposicion(expo), fechaInicioTExposicion(listaExposiciones->exposicion)) == -1){
        nuevoNodo->sig = listaExposiciones;
        listaExposiciones = nuevoNodo;
        
    }else{
        
        TListaExposiciones aux = listaExposiciones;
        TListaExposiciones aux2 = NULL;
        
        while (aux != NULL &&
            compararTFechas(fechaInicioTExposicion(expo), fechaInicioTExposicion(aux->exposicion)) == 1)
        {
            aux2 = aux;
            aux = aux->sig;
        }

        //en el fondo
        if(aux == NULL){
            aux2->sig = nuevoNodo;
        //en el medio
        }else{
            nuevoNodo->sig = aux->sig;
            aux->sig = nuevoNodo;
            nuevoNodo->exposicion = aux->exposicion;
            aux->exposicion = expo;
        }
        
        aux =NULL;
        aux2 = NULL;
    }

}

bool perteneceExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo){ 
    while (listaExposiciones != NULL && idTExposicion(listaExposiciones->exposicion) != idExpo)
    {
        listaExposiciones = listaExposiciones->sig;
    }
    
    return listaExposiciones != NULL;
}

TExposicion obtenerExposicionTListaExposiciones(TListaExposiciones listaExposiciones, int idExpo){ 
    
    if (listaExposiciones != NULL)
    {
        while (listaExposiciones!=NULL && idTExposicion(listaExposiciones->exposicion) != idExpo)
        {
            listaExposiciones = listaExposiciones->sig;
        }
        return listaExposiciones->exposicion;
    }
    
    return NULL; }

bool esVaciaTListaExposiciones(TListaExposiciones listaExposiciones){ return listaExposiciones == NULL; }

void imprimirTListaExposiciones(TListaExposiciones listaExposiciones){
    while (listaExposiciones != NULL)
    {
        imprimirTExposicion(listaExposiciones->exposicion);
        listaExposiciones = listaExposiciones->sig;
    }
    
}

void liberarTListaExposiciones(TListaExposiciones &listaExposiciones, bool liberarExposiciones){
    TListaExposiciones aux;
    while (listaExposiciones != NULL)
    {
        aux = listaExposiciones->sig;
        if(liberarExposiciones){liberarTExposicion(listaExposiciones->exposicion);}
        delete listaExposiciones;
        listaExposiciones = aux;
    }
    
}

TListaExposiciones obtenerExposicionesFinalizadas(TListaExposiciones &listaExposiciones, TFecha fecha){ 
    if(listaExposiciones != NULL){
        TListaExposiciones exposicionesFinalizadas = crearTListaExposicionesVacia();
        TListaExposiciones aux = listaExposiciones;
        TListaExposiciones anterior = NULL;

        while (aux != NULL)
        {
            if (compararTFechas(fechaFinTExposicion(aux->exposicion), fecha) == -1)
            {
                agregarExposicionTListaExposiciones(exposicionesFinalizadas, aux->exposicion);
                
                if(listaExposiciones == aux){
                    listaExposiciones = listaExposiciones->sig;
                }else{
                    anterior->sig = aux->sig;   
                }

                TListaExposiciones borrar = aux;
                aux = aux->sig; 
                delete borrar;
                borrar = NULL;
            }else{
                anterior = aux;
                aux = aux->sig; 
            }
            
        }
        anterior =NULL;
        aux = NULL;
        return exposicionesFinalizadas;
    }
    return NULL;

}              

TListaExposiciones obtenerExposicionesActivas(TListaExposiciones &listaExposiciones, TFecha fecha){ 
    if(listaExposiciones != NULL){
        TListaExposiciones exposicionesActivas = crearTListaExposicionesVacia();
        TListaExposiciones aux = listaExposiciones;
        TListaExposiciones anterior = NULL;

        while (aux != NULL)
        {
            if (!(compararTFechas(fechaFinTExposicion(aux->exposicion), fecha) == -1 
            || compararTFechas(fechaInicioTExposicion(aux->exposicion),fecha) == 1))
            {
                agregarExposicionTListaExposiciones(exposicionesActivas, aux->exposicion);
                
                if(listaExposiciones == aux){
                    listaExposiciones = listaExposiciones->sig;
                }else{
                    anterior->sig = aux->sig;   
                }

                TListaExposiciones borrar = aux;
                aux = aux->sig; 
                delete borrar;
                borrar = NULL;
            }else{
                anterior = aux;
                aux = aux->sig;
            }
            
        }
        anterior =NULL;
        aux = NULL;
        return exposicionesActivas;
    }
    return NULL;

}

bool esCompatibleTListaExposiciones(TListaExposiciones listaExposiciones, TExposicion expo){ 
    while (listaExposiciones != NULL && sonExposicionesCompatibles(listaExposiciones->exposicion, expo))
    {
        listaExposiciones = listaExposiciones->sig;
    }
    
    return listaExposiciones == NULL;
}

void insFinal(TListaExposiciones &lista,TListaExposiciones &ult, TExposicion expo){
    TListaExposiciones nuevoNodo = new rep_listaexposiciones;
    nuevoNodo->sig = NULL;
    nuevoNodo->exposicion = expo;

    if(lista != NULL){
        ult->sig = nuevoNodo;
        ult = ult->sig;
    }else{
        ult = lista = nuevoNodo;
    }
}

TListaExposiciones unirListaExposiciones(TListaExposiciones listaExpo1, TListaExposiciones listaExpo2){ 
    TListaExposiciones unionListaExposiciones = NULL;
    TListaExposiciones ult = unionListaExposiciones;
    
    while (listaExpo1 != NULL && listaExpo2 != NULL)
    {
        if(compararTFechas(fechaInicioTExposicion(listaExpo1->exposicion),fechaInicioTExposicion(listaExpo2->exposicion)) == 1){
            insFinal(unionListaExposiciones, ult, listaExpo2->exposicion);
            listaExpo2 = listaExpo2->sig;
        }else{
            insFinal(unionListaExposiciones, ult, listaExpo1->exposicion);
            listaExpo1=listaExpo1->sig;
        }
    }
    
    
    while (listaExpo1 != NULL)
    {
        insFinal(unionListaExposiciones, ult, listaExpo1->exposicion);
        listaExpo1=listaExpo1->sig;
    }
    while (listaExpo2 != NULL)
    {
        insFinal(unionListaExposiciones, ult, listaExpo2->exposicion);
        listaExpo2=listaExpo2->sig;
    }
    

    return unionListaExposiciones;
}

// Agregados tarea 4


int cantidadExposicionesTListaExposiciones(TListaExposiciones listaExpo){
    int cantidad = 0;
    if (listaExpo != NULL)
    {
        while (listaExpo != NULL)
        {
            cantidad ++;
            listaExpo = listaExpo->sig;
        }    
    }
    
    return cantidad;
}

TExposicion obtenerNesimaExposicionTListaExposiciones(TListaExposiciones listaExpo, int n){
    
    if (listaExpo != NULL)
    {
        TListaExposiciones iter = listaExpo;
        int cant = 1;
        while (iter != NULL && n > cant)
        {
            cant++;
            iter = iter->sig;
        }
        if(iter != NULL){
            return iter->exposicion;
        }
    }
    
    return NULL;
}
