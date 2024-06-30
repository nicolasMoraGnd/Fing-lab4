#include "../include/galeria.h"
#include <assert.h>

struct rep_galeria{
    TColeccionPiezas piezas;
    TFecha fecha;
    TListaExposiciones finalizadas;
    TListaExposiciones activas;
    TListaExposiciones futuras;
    
    TVisitaDia visita;
    THashVisitaDia hashVisita;
    TConjuntoPiezas stockPiezas;
};

void agregarPiezaTGaleria(TGaleria galeria, TPieza pieza){
    if (galeria->piezas == NULL)
    {
        galeria->piezas = crearColeccionPiezasVacia();
        insertarPiezaColeccionPiezas(galeria->piezas, pieza);
    }else{
        insertarPiezaColeccionPiezas(galeria->piezas, pieza);
    }

    insertarTConjuntoPiezas(galeria->stockPiezas, idTPieza(pieza));
    
}

void agregarExposicionTGaleria(TGaleria galeria, TExposicion expo){
    //caso de finalizadas
    if(compararTFechas(fechaFinTExposicion(expo), galeria->fecha) == -1){
        agregarExposicionTListaExposiciones(galeria->finalizadas, expo);
    //caso de futuras
    }else if(compararTFechas(fechaInicioTExposicion(expo), galeria->fecha) == 1){
        agregarExposicionTListaExposiciones(galeria->futuras,expo);
    }else{
        agregarExposicionTListaExposiciones(galeria->activas, expo);
    }
    
}


void agregarPiezaAExposicionTGaleria(TGaleria galeria, int idPieza, int idExpo){
    TPieza piezaId = crearTPieza(idPieza,"" , "", "", NULL);
    TExposicion ExposicionAgregar;
    
    if(perteneceExposicionTListaExposiciones(galeria->finalizadas, idExpo)){
        ExposicionAgregar = obtenerExposicionTListaExposiciones(galeria->finalizadas, idExpo);
    }else if(perteneceExposicionTListaExposiciones(galeria->activas, idExpo)){
        ExposicionAgregar = obtenerExposicionTListaExposiciones(galeria->activas, idExpo);
    }else if(perteneceExposicionTListaExposiciones(galeria->futuras, idExpo)){
        ExposicionAgregar = obtenerExposicionTListaExposiciones(galeria->futuras, idExpo);
    }

    if(ExposicionAgregar != NULL){
        agregarATExposicion(ExposicionAgregar, piezaId);
    }

    liberarTPieza(piezaId);
}

void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha){
    
    assert(compararTFechas(fecha, galeria->fecha) == 1);
    liberarTFecha(galeria->fecha);
    //puede ser que haya que copiar la fecha, nose.
    galeria->fecha = copiarTFecha(fecha);
    
    //actualizacion de las listaExposicion
    TListaExposiciones dosListas = unirListaExposiciones(galeria->finalizadas, galeria->activas);
    TListaExposiciones listasUnidas = unirListaExposiciones(dosListas, galeria->futuras);

    liberarTListaExposiciones(dosListas, false);
    liberarTListaExposiciones(galeria->finalizadas, false);
    liberarTListaExposiciones(galeria->activas,false);
    liberarTListaExposiciones(galeria->futuras,false);

    galeria->finalizadas = obtenerExposicionesFinalizadas(listasUnidas, galeria->fecha);
    galeria->activas = obtenerExposicionesActivas(listasUnidas, galeria->fecha);
    galeria->futuras = listasUnidas;

    listasUnidas = NULL;

    //actualizacion VisitaDia
    
    agregarVisitaDiaTHashVisitaDia(galeria->hashVisita, galeria->visita);
    galeria->visita = crearTVisitaDia(fecha, maxGruposTVisitaDia(galeria->visita));
    
}

void imprimirExposicionesFinalizadasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->finalizadas);
}

void imprimirExposicionesActivasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->activas);
}

void imprimirExposicionesFuturasTGaleria(TGaleria galeria){
    imprimirTListaExposiciones(galeria->futuras);
}

bool esCompatibleExposicionTGaleria(TGaleria galeria, TExposicion expo){ 
    return esCompatibleTListaExposiciones(galeria->finalizadas, expo) 
        && esCompatibleTListaExposiciones(galeria->futuras, expo)
        && esCompatibleTListaExposiciones(galeria->activas, expo);
}

TGaleria crearTGaleria(TFecha fecha){
    TGaleria nuevaGaleria = new rep_galeria;
    nuevaGaleria->fecha = copiarTFecha(fecha);
    nuevaGaleria->piezas = NULL;
    nuevaGaleria->finalizadas = NULL;
    nuevaGaleria->activas = NULL;
    nuevaGaleria->futuras = NULL;

    nuevaGaleria->visita = crearTVisitaDia(fecha, MAX_GRUPOS_VISITA_DIA);
    nuevaGaleria->hashVisita = crearTHashVisitaDia(MAX_GRUPOS_VISITA_DIA);
    nuevaGaleria->stockPiezas = crearTConjuntoPiezas(MAX_PIEZAS);

    return nuevaGaleria;
}

void liberarTGaleria(TGaleria &galeria){
    liberarColeccionPiezas(galeria->piezas);
    liberarTFecha(galeria->fecha);
    liberarTListaExposiciones(galeria->finalizadas, true);
    liberarTListaExposiciones(galeria->activas, true);
    liberarTListaExposiciones(galeria->futuras, true);

    liberarTVisitaDia(galeria->visita);
    liberarTHashVisitaDia(galeria->hashVisita);
    liberarTConjuntoPiezas(galeria->stockPiezas);

    delete galeria;
    galeria = NULL;
}

// Funciones tarea 4

//to do: refactorizar y hacer bien, hay que entrgar burises
TConjuntoPiezas piezasEnExposicionTGaleria(TGaleria galeria){
    if(galeria->activas != NULL){
        TConjuntoPiezas piezasRetorno = unionTConjuntoPiezas(NULL, obtenerPiezasTExposicion(obtenerNesimaExposicionTListaExposiciones(galeria->activas, 1)));
        TConjuntoPiezas piezasAux = NULL;
        TExposicion aux;
        int cantidadExpos = cantidadExposicionesTListaExposiciones(galeria->activas);

        for (int i = 2; i <= cantidadExpos; i++)
        {
            piezasAux = piezasRetorno;

            aux = obtenerNesimaExposicionTListaExposiciones(galeria->activas, i);

            piezasRetorno = unionTConjuntoPiezas(piezasAux, obtenerPiezasTExposicion(aux));
            liberarTConjuntoPiezas(piezasAux);      
        }

        return piezasRetorno;
    }else{
        return NULL;
    }
}

float indiceFelicidadVisitanteTGaleria(TGaleria galeria, TVisitante visitante){
    return 0.0;
}

void llegaGrupoTGaleria(TGaleria galeria, TGrupoABB grupoABB){
    encolarGrupoTVisitaDia(galeria->visita, grupoABB);
}

TConjuntoPiezas piezasEnReservaTGaleria(TGaleria galeria){    
    return NULL;
}

TVisitaDia obtenerVisitaDiaTGaleria(TGaleria galeria, TFecha fecha){
    if(compararTFechas(fecha, galeria->fecha) == 0){
        return galeria->visita;
    }
    return obtenerVisitaDiaTHashVisitaDia(galeria->hashVisita,fecha);
}
