#include "../include/galeria.h"

struct rep_galeria{
    TColeccionPiezas piezas;
    TFecha fecha;
    TListaExposiciones finalizadas;
    TListaExposiciones activas;
    TListaExposiciones futuras;
};

TGaleria crearTGaleria(TFecha fecha){ 
    TGaleria nuevaGaleria = new rep_galeria;
    nuevaGaleria->fecha = fecha;
    nuevaGaleria->piezas = NULL;
    nuevaGaleria->finalizadas = NULL;
    nuevaGaleria->activas = NULL;
    nuevaGaleria->futuras = NULL;
    
    return nuevaGaleria;
    
}

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





//perdida de memoria, nidea que
void avanzarAFechaTGaleria(TGaleria galeria, TFecha fecha){
    liberarTFecha(galeria->fecha);
    galeria->fecha = fecha;
     
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

void liberarTGaleria(TGaleria &galeria){
    liberarColeccionPiezas(galeria->piezas);
    liberarTFecha(galeria->fecha);
    liberarTListaExposiciones(galeria->finalizadas, true);
    liberarTListaExposiciones(galeria->activas, true);
    liberarTListaExposiciones(galeria->futuras, true);

    delete galeria;
    galeria = NULL;
}
