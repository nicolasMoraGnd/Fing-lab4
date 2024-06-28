#include "../include/galeria.h"

struct rep_galeria{
    TColeccionPiezas piezas;
    TFecha fecha;
    TListaExposiciones finalizadas;
    TListaExposiciones activas;
    TListaExposiciones futuras;
    
    TVisitaDia visita;
    THashVisitaDia hashVisita;
};

void agregarPiezaTGaleria(TGaleria galeria, TPieza pieza){
    if (galeria->piezas == NULL)
    {
        galeria->piezas = crearColeccionPiezasVacia();
        insertarPiezaColeccionPiezas(galeria->piezas, pieza);
    }else{
        insertarPiezaColeccionPiezas(galeria->piezas, pieza);
    }
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
    nuevaGaleria->fecha = fecha;
    nuevaGaleria->piezas = NULL;
    nuevaGaleria->finalizadas = NULL;
    nuevaGaleria->activas = NULL;
    nuevaGaleria->futuras = NULL;

    nuevaGaleria->visita = crearTVisitaDia(fecha, MAX_GRUPOS_VISITA_DIA);
    nuevaGaleria->hashVisita = crearTHashVisitaDia(MAX_GRUPOS_VISITA_DIA);
    
    return nuevaGaleria;
}

void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha){
}

void liberarTGaleria(TGaleria &galeria){
    liberarColeccionPiezas(galeria->piezas);
    liberarTFecha(galeria->fecha);
    liberarTListaExposiciones(galeria->finalizadas, true);
    liberarTListaExposiciones(galeria->activas, true);
    liberarTListaExposiciones(galeria->futuras, true);

    liberarTVisitaDia(galeria->visita);
    liberarTHashVisitaDia(galeria->hashVisita);

    delete galeria;
    galeria = NULL;
}

// Funciones tarea 4

TConjuntoPiezas piezasEnExposicionTGaleria(TGaleria galeria){
    return NULL;
}

float indiceFelicidadVisitanteTGaleria(TGaleria galeria, TVisitante visitante){
    return 0.0;
}

void llegaGrupoTGaleria(TGaleria galeria, TGrupoABB grupoABB){
}

TConjuntoPiezas piezasEnReservaTGaleria(TGaleria galeria){    
    return NULL;
}

TVisitaDia obtenerVisitaDiaTGaleria(TGaleria galeria, TFecha fecha){
    return NULL;
}
