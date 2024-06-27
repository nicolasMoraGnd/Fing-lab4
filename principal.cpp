/*
  Módulo principal de la Tarea 1.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#define cmd_es(nom_comando, cmd) (0 == strcmp(nom_comando, cmd))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/coleccionTGrupos.h"
#include "include/coleccionPiezas.h"
#include "include/galeria.h"
#include "include/hashVisitaDia.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

#define NOMBRE_PIEZA_DUMMY "Pieza Dummy"
#define NOMBRE_AUTOR_PIEZA_DUMMY "Nombre Dummy"
#define APELLIDO_AUTOR__PIEZA_DUMMY "Apellido Dummy"

///////////////////////////////
// Funciones main para Fecha //
///////////////////////////////

void leerFecha(TFecha &fecha); // Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void main_crearFecha(TFecha &fecha); // Crea una fecha y la almacena en la variable fecha
void main_liberarFecha(TFecha &fecha); // Libera la memoria de la variable fecha
void main_imprimirFecha(TFecha fecha); // Imprime la fecha almacenada en la variable fecha
void main_aumentarDias(TFecha &fecha); // Aumenta la fecha almacenada en la variable fecha en la cantidad de días indicada
void main_compararFechas(); // Compara dos fechas leidas de la entrada

////////////////////////////////////
// Funciones main para Visitantes //
////////////////////////////////////
void main_crearVisitante(TVisitante &visitante); // Crea un visitante y lo almacena en la variable 'visitante'
void main_imprimirEdadVisitante(TVisitante visitante); // Imprime la edad del visitante almacenado en la variable 'visitante'
void main_imprimirIdVisitante(TVisitante visitante); // Imprime la id del visitante almacenado en la variable 'visitante'
void main_imprimirNombreYApellidoVisitante(TVisitante visitante); // Imprime el nombre y apelldio del visitante almacenado en la variable 'visitante'
void main_imprimirVisitante(TVisitante visitante); // Imprime el visitante almacenado en la variable 'visitante'
void main_copiarVisitante(TVisitante visitante); // Copia al visitante en visitante
void main_liberarVisitante(TVisitante &visitante); // Libera la memoria asociada al visitante guardado en la variable 'visitante'

////////////////////////////////////
//   Funciones main para Piezas   //
////////////////////////////////////
void main_crearTPieza(TPieza &pieza, TFecha &fecha);
void main_imprimirTPieza(TPieza pieza);
void main_liberarTPieza(TPieza &pieza);
void main_idTPieza(TPieza pieza);

//////////////////////////////////////////////
//   Funciones main para Colección Piezas   //
//////////////////////////////////////////////
void main_crearColeccionPiezas(TColeccionPiezas &coleccionPiezas);
void main_agregarColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza &pieza);
void main_imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas);
void main_liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas);
void main_esVaciaColeccionPiezas(TColeccionPiezas coleccionPiezas);
void main_existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas);
void main_obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas);
void main_removerDeColeccionPiezas(TColeccionPiezas &coleccionPiezas);

//////////////////////////////////
// Funciones main para GrupoABB //
//////////////////////////////////
void main_crearGrupoABB(TGrupoABB &grupo, int &generadorID); // Crea un grupoABB y la almacena en la variable grupo
void main_agregarVisitanteAGrupoABB(TGrupoABB &grupo, TVisitante &visitante); // Agrega el visitante almacenada en la variable 'visitante' al grupo almacenado en la variable grupo
void main_imprimirGrupoABB(TGrupoABB grupo); // Imprime toda la información del grupoABB almacenado en la variable grupo
void main_liberarGrupoABB(TGrupoABB &grupo);
void main_existeEnGrupoABB(TGrupoABB grupo);
void main_obtenerVisitanteGrupoABB(TGrupoABB grupo);
void main_alturaGrupoABB(TGrupoABB grupo);
void main_maxIdGrupoABB(TGrupoABB grupo);
void main_cantidadVisitantesGrupoABB(TGrupoABB grupo);
void main_edadPromedioGrupoABB(TGrupoABB grupo);
void main_removerDeGrupoABB(TGrupoABB &grupo);
void main_obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupo);
void main_alturaGrupoABBTiempo(int &generadorID);
void main_obtenerExisteVisitanteGrupoABBTiempo(int &generadorID);

//////////////////////////////////////////
// Funciones main para ColeccionTGrupos //
//////////////////////////////////////////
void main_crearColeccionGrupos(TColeccionTGrupos &coleccion);
void main_agregarGrupoAColeccion(TColeccionTGrupos &coleccion, TGrupoABB &grupo);
void main_imprimirColeccionTGrupos(TColeccionTGrupos coleccion);
void main_imprimirColeccionInvertidaTGrupos(TColeccionTGrupos coleccion);
void main_obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccion);
void main_cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccion);
void main_obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccion);
void main_removerUltimoColeccionTGrupos(TColeccionTGrupos coleccion);
void main_removerNesimoColeccionTGrupos(TColeccionTGrupos coleccion);
void main_liberarColeccionTGrupos(TColeccionTGrupos &coleccion);
void main_obtenerVisitantesRepetidos(TColeccionTGrupos coleccion);
void main_visitanteMasRepetido(TColeccionTGrupos coleccion);

///////////////////////////////////
// Funciones main para VisitaDia //
///////////////////////////////////
void main_crearVisitaDia(TVisitaDia &visitaDia);
void main_imprimirVisitaDia(TVisitaDia &visitaDia);
void main_encolarGrupoVisitaDia(TVisitaDia &visitaDia, TGrupoABB &grupo);
void main_cantidadGruposVisitaDia(TVisitaDia visitaDia);
void main_desencolarGrupoVisitaDia(TVisitaDia &visitaDia);
void main_liberarVisitaDia(TVisitaDia &visitaDia);
void main_invertirPrioridadTVisitaDia(TVisitaDia &visitaDia);
void main_estaEnTVisitaDia(TVisitaDia visitaDia);
void main_prioridadTVisitaDia(TVisitaDia visitaDia);
void main_maxGruposTVisitaDia(TVisitaDia visitaDia);
void main_fechaTVisitaDia(TVisitaDia visitaDia);
void main_masPrioritarioTVisitaDia(TVisitaDia visitaDia);

///////////////////////////////////
//        Conjunto Piezas        //
///////////////////////////////////
void main_crearConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas);
void main_esVacioConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_insertarConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas);
void main_borrarDeConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas);
void main_perteneceConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_cardinalConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_cantMaxConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_imprimirConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_liberarConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas);
void main_unionConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_interseccionConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);
void main_diferenciaConjuntoPiezas(TConjuntoPiezas conjuntoPiezas);

///////////////////////////////////
//          Exposicion           //
///////////////////////////////////
void main_crearExposicion(TExposicion &expo);
void main_agregarAExposicion(TExposicion expo);
void main_perteneceAExposicion(TExposicion expo);
void main_idExposicion(TExposicion expo);
void main_imprimirExposicion(TExposicion expo);
void main_fechaInicioTExposicion(TExposicion expo);
void main_fechaFinTExposicion(TExposicion expo);
void main_sonExposicionesCompatibles(TExposicion expo);
void main_liberarTExposicion(TExposicion &expo);

///////////////////////////////////
//       Lista Exposiciones      //
///////////////////////////////////
void main_crearListaExposiciones(TListaExposiciones &listaExpo);
void main_agregarAListaExposiciones(TListaExposiciones &listaExpo, TExposicion &expo);
void main_esVaciaListaExposiciones(TListaExposiciones listaExpo);
void main_imprimirListaExposiciones(TListaExposiciones listaExpo);
void main_liberarListaExposiciones(TListaExposiciones &listaExpo);
void main_perteneceExposicionListaExposiciones(TListaExposiciones listaExposiciones);
void main_obtenerExposicionListaExposiciones(TListaExposiciones listaExposiciones);
void main_obtenerExposicionesFinalizadas(TListaExposiciones &listaExpo);
void main_obtenerExposicionesActivas(TListaExposiciones &listaExpo);
void main_esCompatibleListaExposiciones(TListaExposiciones listaExposiciones, TExposicion expo);
void main_unirListaExposiciones(TListaExposiciones listaExpo);

///////////////////////////////////
//             Galeria           //
///////////////////////////////////
void main_crearGaleria(TGaleria &galeria);
void main_agregarPiezaGaleria(TGaleria galeria, TPieza &pieza);
void main_agregarExposicionGaleria(TGaleria galeria, TExposicion &expo);
void main_agregarPiezaAExposicionGaleria(TGaleria galeria);
void main_avanzarAFechaGaleria(TGaleria galeria);
void main_imprimirExposicionesFinalizadasGaleria(TGaleria galeria);
void main_imprimirExposicionesActivasGaleria(TGaleria galeria);
void main_imprimirExposicionesFuturasGaleria(TGaleria galeria);
void main_esCompatibleExposicionGaleria(TGaleria galeria, TExposicion expo);
void main_liberarGaleria(TGaleria &galeria);

void main_llegaGrupoTGaleria(TGaleria galeria, TGrupoABB &grupo);
void main_obtenerVisitaDiaTGaleria(TGaleria galeria);
void main_piezasEnExposicionTGaleria(TGaleria galeria);
void main_indiceFelicidadVisitanteTGaleria(TGaleria galeria, TVisitante visitante);
void main_piezasEnReservaTGaleria(TGaleria galeria);

///////////////////////////////////
//       Hash Visita Dia         //
///////////////////////////////////
void main_crearTHashVisitaDia(THashVisitaDia &hash);
void main_agregarVisitaDiaTHashVisitaDia(THashVisitaDia hash, TVisitaDia &visitaDia);
void main_imprimirTHashVisitaDia(THashVisitaDia hash);
void main_obtenerVisitaDiaTHashVisitaDia(THashVisitaDia hash);
void main_perteneceVisitaDiaTHashVisitaDia(THashVisitaDia hash);
void main_liberarTHashVisitaDia(THashVisitaDia &hash);

// AGREGADOS TAREA 4
void main_agregarPiezasFavoritasTVisitante(TVisitante visitante);
void main_obtenerPiezasFavoritasTVisitante(TVisitante visitante);
void main_cantidadExposicionesTListaExposiciones(TListaExposiciones listaExpo);
void main_obtenerNesimaExposicionTListaExposiciones(TListaExposiciones listaExpo);
void main_obtenerPiezasTExposicion(TExposicion expo);

////////////////////////////////////////
//           Tests de tiempo          //
////////////////////////////////////////
void main_testTiempoVisitaDia();
void main_testTiempoHashVisitaDia();

// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    int generadorID = 0;
    TFecha fecha = NULL;
    TVisitante visitante = NULL;
    TGrupoABB grupo = NULL;
    TPieza pieza = NULL;
    TColeccionPiezas coleccionPiezas = NULL;
    TColeccionTGrupos coleccionGrupos = NULL;

    TVisitaDia visitaDia = NULL;
    TConjuntoPiezas conjuntoPiezas = NULL;
    TExposicion expo = NULL;
    TListaExposiciones listaExpo = NULL;
    TGaleria galeria = NULL;

    THashVisitaDia hash = NULL;

    char restoLinea[MAX_LINEA + 1];
    char cmd[MAX_PALABRA];

    int cont_comandos = 0;
    bool seguir = true;
    printf("Bienvenido al programa principal de ArteProg. Por favor ingrese su comando:\n");
    while (seguir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%u> ", cont_comandos);

        // leer el comando en la variable cmd
        leerChars(cmd);

        // procesar el comando
        if (cmd_es("Fin", cmd)) {  // Termina el programa
            seguir = false;
            printf("Fin.\n");

        } else if (cmd_es("#", cmd)) {  // Imprime el comentario luego del #
            leerRestoLinea(restoLinea);
            printf("# %s.\n", restoLinea);

            ///////////////////////////////////
            /* Funciones para testear fecha */
            ///////////////////////////////////

        } else if (cmd_es("crearFecha", cmd)) {  
            main_crearFecha(fecha);
        } else if (cmd_es("imprimirFecha", cmd)) {  
            main_imprimirFecha(fecha);
        } else if (cmd_es("liberarFecha", cmd)) {  
            main_liberarFecha(fecha);
        } else if (cmd_es("aumentarDias", cmd)) {  
            main_aumentarDias(fecha);
        } else if (cmd_es("compararFechas", cmd)) {  
            main_compararFechas();

            //////////////////////////////////////
            /* Funciones para testear visitante */
            //////////////////////////////////////

        } else if (cmd_es("crearVisitante", cmd)) {  
            main_crearVisitante(visitante);
        } else if (cmd_es("imprimirEdadVisitante", cmd)) {  
            main_imprimirEdadVisitante(visitante);
        } else if (cmd_es("imprimirIdVisitante",cmd)){
            main_imprimirIdVisitante(visitante);
        } else if (cmd_es("imprimirNombreYApellidoVisitante", cmd)){     
            main_imprimirNombreYApellidoVisitante(visitante);
        } else if (cmd_es("imprimirVisitante", cmd)) { 
            main_imprimirVisitante(visitante);
        } else if (cmd_es("copiarVisitante",cmd)){
            main_copiarVisitante(visitante);
        } else if (cmd_es("liberarVisitante", cmd)) {  
            main_liberarVisitante(visitante);      


            ////////////////////////////////////
            //   Funciones main para Piezas   //
            ////////////////////////////////////
        } else if (cmd_es("crearPieza", cmd)) {  
            main_crearTPieza(pieza, fecha);
        } else if (cmd_es("imprimirPieza", cmd)) {  
            main_imprimirTPieza(pieza);
        } else if (cmd_es("liberarPieza", cmd)) {  
            main_liberarTPieza(pieza);
        } else if (cmd_es("idPieza", cmd)) {  
            main_idTPieza(pieza);
        
            //////////////////////////////////////////////
            //   Funciones main para Colección Piezas   //
            //////////////////////////////////////////////
        } else if (cmd_es("crearColeccionPiezas", cmd)) {  
            main_crearColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("agregarColeccionPiezas", cmd)) {  
            main_agregarColeccionPiezas(coleccionPiezas, pieza);
        } else if (cmd_es("imprimirColeccionPiezas", cmd)) {  
            main_imprimirColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("liberarColeccionPiezas", cmd)) {  
            main_liberarColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("esVaciaColeccionPiezas", cmd)) {  
            main_esVaciaColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("existePiezaColeccionPiezas", cmd)){ 
            main_existePiezaColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("obtenerPiezaColeccionPiezas", cmd)) {  
            main_obtenerPiezaColeccionPiezas(coleccionPiezas);
        } else if (cmd_es("removerDeColeccionPiezas", cmd)) {  
            main_removerDeColeccionPiezas(coleccionPiezas);


            ///////////////////////////////////
            /* Funciones para testear grupo */
            ///////////////////////////////////
        } else if (cmd_es("crearGrupoABB", cmd)) {  // Crea un grupo y la almacena en la variable grupo
            main_crearGrupoABB(grupo, generadorID);
        } else if (cmd_es("agregarAGrupoABB", cmd)) { 
            main_agregarVisitanteAGrupoABB(grupo, visitante);
        } else if (cmd_es("imprimirGrupoABB", cmd)) { 
            main_imprimirGrupoABB(grupo);
        } else if (cmd_es("existeEnGrupoABB", cmd)) { 
            main_existeEnGrupoABB(grupo);
        } else if (cmd_es("obtenerVisitanteGrupoABB", cmd)) { 
            main_obtenerVisitanteGrupoABB(grupo);
        } else if (cmd_es("alturaGrupoABB", cmd)) { 
            main_alturaGrupoABB(grupo);
        } else if (cmd_es("maxIdGrupoABB", cmd)) { 
            main_maxIdGrupoABB(grupo);
        } else if (cmd_es("cantidadVisitantesGrupoABB", cmd)) { 
            main_cantidadVisitantesGrupoABB(grupo);
        } else if (cmd_es("edadPromedioGrupoABB", cmd)) { 
            main_edadPromedioGrupoABB(grupo);
        } else if (cmd_es("removerDeGrupoABB", cmd)) { 
            main_removerDeGrupoABB(grupo);
        } else if (cmd_es("liberarGrupoABB", cmd)) { 
            main_liberarGrupoABB(grupo);
        } else if (cmd_es("obtenerNesimoVisitanteGrupoABB", cmd)) { 
            main_obtenerNesimoVisitanteTGrupoABB(grupo);
        } else if (cmd_es("alturaGrupoABBTiempo", cmd)) { 
            main_alturaGrupoABBTiempo(generadorID);
        } else if (cmd_es("obtenerExisteVisitanteGrupoABBTiempo", cmd)) { 
            main_obtenerExisteVisitanteGrupoABBTiempo(generadorID);

            //////////////////////////////////////////////
            // Funciones para testear ColeccionTGrupos  //
            //////////////////////////////////////////////
        } else if (cmd_es("crearColeccionGrupos", cmd)) { 
            main_crearColeccionGrupos(coleccionGrupos);
        } else if (cmd_es("agregarAColeccionGrupos", cmd)) { 
            main_agregarGrupoAColeccion(coleccionGrupos, grupo);
        } else if (cmd_es("imprimirColeccionGrupos", cmd)) { 
            main_imprimirColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("imprimirInvertidaColeccionGrupos", cmd)) { 
            main_imprimirColeccionInvertidaTGrupos(coleccionGrupos);
        } else if (cmd_es("obtenerNesimoColeccionGrupos", cmd)) { 
            main_obtenerNesimoColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("cantidadColeccionGrupos", cmd)) { 
            main_cantidadTGruposColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("obtenerPrimeroColeccionGrupos", cmd)) { 
            main_obtenerPrimeroColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("removerUltimoColeccionGrupos", cmd)) { 
            main_removerUltimoColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("removerNesimoColeccionGrupos", cmd)) { 
            main_removerNesimoColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("liberarColeccionGrupos", cmd)) { 
            main_liberarColeccionTGrupos(coleccionGrupos);
        } else if (cmd_es("obtenerVisitantesRepetidos", cmd)) { 
            main_obtenerVisitantesRepetidos(coleccionGrupos);
        } else if (cmd_es("visitanteMasRepetido", cmd)) { 
            main_visitanteMasRepetido(coleccionGrupos);
    

            ///////////////////////////////////
            // Funciones main para VisitaDia //
            ///////////////////////////////////
        } else if (cmd_es("crearVisitaDia", cmd)) { 
            main_crearVisitaDia(visitaDia);
        } else if (cmd_es("imprimirVisitaDia", cmd)) { 
            main_imprimirVisitaDia(visitaDia);
        } else if (cmd_es("encolarGrupoVisitaDia", cmd)) { 
            main_encolarGrupoVisitaDia(visitaDia, grupo);
        } else if (cmd_es("cantidadGruposVisitaDia", cmd)) { 
            main_cantidadGruposVisitaDia(visitaDia);
        } else if (cmd_es("desencolarGrupoVisitaDia", cmd)) { 
            main_desencolarGrupoVisitaDia(visitaDia);
        } else if (cmd_es("liberarVisitaDia", cmd)) { 
            main_liberarVisitaDia(visitaDia);
        } else if (cmd_es("invertirPrioridadVisitaDia", cmd)) {  
            main_invertirPrioridadTVisitaDia(visitaDia);        
        } else if (cmd_es("estaEnVisitaDia", cmd)) {  
            main_estaEnTVisitaDia(visitaDia);        
        } else if (cmd_es("prioridadVisitaDia", cmd)) {  
            main_prioridadTVisitaDia(visitaDia);        
        } else if (cmd_es("maxGruposVisitaDia", cmd)) {  
            main_maxGruposTVisitaDia(visitaDia);        
        } else if (cmd_es("fechaVisitaDia", cmd)) {  
            main_fechaTVisitaDia(visitaDia);        
        } else if (cmd_es("masPrioritarioVisitaDia", cmd)) {  
            main_masPrioritarioTVisitaDia(visitaDia);        


            ///////////////////////////////////
            //        Conjunto Piezas        //
            ///////////////////////////////////
        } else if (cmd_es("crearConjuntoPiezas", cmd)) { 
            main_crearConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("esVacioConjuntoPiezas", cmd)) { 
            main_esVacioConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("insertarConjuntoPiezas", cmd)) { 
            main_insertarConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("borrarDeConjuntoPiezas", cmd)) { 
            main_borrarDeConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("perteneceConjuntoPiezas", cmd)) { 
            main_perteneceConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("cardinalConjuntoPiezas", cmd)) { 
            main_cardinalConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("cantMaxConjuntoPiezas", cmd)) { 
            main_cantMaxConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("imprimirConjuntoPiezas", cmd)) { 
            main_imprimirConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("liberarConjuntoPiezas", cmd)) { 
            main_liberarConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("unionConjuntoPiezas", cmd)) { 
            main_unionConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("interseccionConjuntoPiezas", cmd)) { 
            main_interseccionConjuntoPiezas(conjuntoPiezas);
        } else if (cmd_es("diferenciaConjuntoPiezas", cmd)) { 
            main_diferenciaConjuntoPiezas(conjuntoPiezas);


            ///////////////////////////////////
            //          Exposicion           //
            ///////////////////////////////////
        } else if (cmd_es("crearExposicion", cmd)) { 
            main_crearExposicion(expo);
        } else if (cmd_es("agregarAExposicion", cmd)) { 
            main_agregarAExposicion(expo);
        } else if (cmd_es("perteneceAExposicion", cmd)) { 
            main_perteneceAExposicion(expo);
        } else if (cmd_es("idExposicion", cmd)) { 
            main_idExposicion(expo);
        } else if (cmd_es("imprimirExposicion", cmd)) { 
            main_imprimirExposicion(expo);
        } else if (cmd_es("fechaInicioExposicion", cmd)) { 
            main_fechaInicioTExposicion(expo);
        } else if (cmd_es("fechaFinExposicion", cmd)) { 
            main_fechaFinTExposicion(expo);
        } else if (cmd_es("sonExposicionesCompatibles", cmd)) { 
            main_sonExposicionesCompatibles(expo);
        } else if (cmd_es("liberarExposicion", cmd)) { 
            main_liberarTExposicion(expo);


            ///////////////////////////////////
            //       Lista Exposiciones      //
            ///////////////////////////////////
        } else if (cmd_es("crearListaExposiciones", cmd)) { 
            main_crearListaExposiciones(listaExpo);
        } else if (cmd_es("agregarAListaExposiciones", cmd)) { 
            main_agregarAListaExposiciones(listaExpo, expo);
        } else if (cmd_es("esVaciaListaExposiciones", cmd)) { 
            main_esVaciaListaExposiciones(listaExpo);
        } else if (cmd_es("imprimirListaExposiciones", cmd)) { 
            main_imprimirListaExposiciones(listaExpo);
        } else if (cmd_es("liberarListaExposiciones", cmd)) { 
            main_liberarListaExposiciones(listaExpo);
        } else if (cmd_es("perteneceExposicionListaExposiciones", cmd)) { 
            main_perteneceExposicionListaExposiciones(listaExpo);
        } else if (cmd_es("obtenerExposicionListaExposiciones", cmd)) { 
            main_obtenerExposicionListaExposiciones(listaExpo);
        } else if (cmd_es("obtenerExposicionesFinalizadas", cmd)) { 
            main_obtenerExposicionesFinalizadas(listaExpo);
        } else if (cmd_es("obtenerExposicionesActivas", cmd)) { 
            main_obtenerExposicionesActivas(listaExpo);
        } else if (cmd_es("esCompatibleListaExposiciones", cmd)) { 
            main_esCompatibleListaExposiciones(listaExpo, expo);
        } else if (cmd_es("unirListaExposiciones", cmd)) { 
            main_unirListaExposiciones(listaExpo);


            ///////////////////////////////////
            //            Galeria            //
            ///////////////////////////////////
        } else if (cmd_es("crearGaleria", cmd)) { 
            main_crearGaleria(galeria);
        } else if (cmd_es("agregarPiezaGaleria", cmd)) { 
            main_agregarPiezaGaleria(galeria, pieza);
        } else if (cmd_es("agregarExposicionGaleria", cmd)) { 
            main_agregarExposicionGaleria(galeria, expo);
        } else if (cmd_es("agregarPiezaAExposicionGaleria", cmd)) { 
            main_agregarPiezaAExposicionGaleria(galeria);
        } else if (cmd_es("avanzarAFechaGaleria", cmd)) { 
            main_avanzarAFechaGaleria(galeria);
        } else if (cmd_es("imprimirExposicionesFinalizadasGaleria", cmd)) { 
            main_imprimirExposicionesFinalizadasGaleria(galeria);
        } else if (cmd_es("imprimirExposicionesActivasGaleria", cmd)) { 
            main_imprimirExposicionesActivasGaleria(galeria);
        } else if (cmd_es("imprimirExposicionesFuturasGaleria", cmd)) { 
            main_imprimirExposicionesFuturasGaleria(galeria);
        } else if (cmd_es("esCompatibleExposicionGaleria", cmd)) { 
            main_esCompatibleExposicionGaleria(galeria, expo);
        } else if (cmd_es("liberarGaleria", cmd)) { 
            main_liberarGaleria(galeria);

        } else if (cmd_es("llegaGrupoGaleria", cmd)) { 
            main_llegaGrupoTGaleria(galeria, grupo);
        } else if (cmd_es("obtenerVisitaDiaGaleria", cmd)) { 
            main_obtenerVisitaDiaTGaleria(galeria);
        } else if (cmd_es("piezasEnExposicionGaleria", cmd)) { 
            main_piezasEnExposicionTGaleria(galeria);
        } else if (cmd_es("indiceFelicidadVisitanteGaleria", cmd)) { 
            main_indiceFelicidadVisitanteTGaleria(galeria, visitante);
        } else if (cmd_es("piezasEnReservaGaleria", cmd)) { 
            main_piezasEnReservaTGaleria(galeria);


            ///////////////////////////////////
            //        Hash Visita Dia        //
            ///////////////////////////////////
            
        } else if (cmd_es("crearHashVisitaDia",cmd)){
            main_crearTHashVisitaDia(hash);
        } else if (cmd_es("agregarVisitaDiaHashVisitaDia", cmd)) {  
            main_agregarVisitaDiaTHashVisitaDia(hash, visitaDia);        
        } else if (cmd_es("imprimirHashVisitaDia", cmd)) {  
            main_imprimirTHashVisitaDia(hash);        
        } else if (cmd_es("obtenerVisitaDiaHashVisitaDia", cmd)) {  
            main_obtenerVisitaDiaTHashVisitaDia(hash);        
        } else if (cmd_es("perteneceVisitaDiaHashVisitaDia", cmd)) {  
            main_perteneceVisitaDiaTHashVisitaDia(hash);        
        } else if (cmd_es("liberarHashVisitaDia", cmd)) {  
            main_liberarTHashVisitaDia(hash);        


            ///////////////////////////////////
            //       Agregados tarea 4       //
            ///////////////////////////////////


        } else if (cmd_es("agregarPiezasFavoritasVisitante",cmd)){
            main_agregarPiezasFavoritasTVisitante(visitante);
        } else if (cmd_es("obtenerPiezasFavoritasVisitante", cmd)) {  
            main_obtenerPiezasFavoritasTVisitante(visitante);        
        } else if (cmd_es("cantidadExposicionesListaExposiciones", cmd)) {  
            main_cantidadExposicionesTListaExposiciones(listaExpo);        
        } else if (cmd_es("obtenerNesimaExposicionListaExposiciones", cmd)) {  
            main_obtenerNesimaExposicionTListaExposiciones(listaExpo);        
        } else if (cmd_es("obtenerPiezasExposicion", cmd)) {  
            main_obtenerPiezasTExposicion(expo);        


        
            ////////////////////////////////////////
            //           Tests de tiempo          //
            ////////////////////////////////////////
        } else if (cmd_es("tiempoVisitaDia", cmd)){
            main_testTiempoVisitaDia();
        } else if (cmd_es("tiempoHashVisitaDia", cmd)){
            main_testTiempoHashVisitaDia();

            
        } else {
            printf("Comando no reconocido.\n");  // Comando no reconocido
        }  
        fgets(restoLinea, MAX_LINEA + 1, stdin);
    }  // while

    return 0;
}  // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha) {
    nat *componentes = new nat[3];
    scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
    fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
    delete[] componentes;
}

void main_crearFecha(TFecha &fecha) {
    assert(fecha == NULL);
    leerFecha(fecha);
    printf("Fecha creada en forma exitosa.\n");
}

void main_liberarFecha(TFecha &fecha) {
    assert(fecha != NULL);
    liberarTFecha(fecha);
    printf("Fecha liberada en forma exitosa.\n");
}

void main_imprimirFecha(TFecha fecha) {
    assert(fecha != NULL);
    imprimirTFecha(fecha);
}

void main_aumentarDias(TFecha &fecha) {
    assert(fecha != NULL);
    nat cantDias = leerNat();
    aumentarTFecha(fecha, cantDias);
    printf("La nueva fecha aplazada %d dias es: \n", cantDias);
    imprimirTFecha(fecha);
}

void main_compararFechas() {
    TFecha fecha1 = NULL, fecha2 = NULL;
    leerFecha(fecha1);
    leerFecha(fecha2);
    int comp = compararTFechas(fecha1, fecha2);
    if (comp == 0) {
        printf("Las fechas son iguales. \n");
    } else if (comp == 1) {
        printf("La primera fecha es posterior a la segunda. \n");
    } else
        printf("La primera fecha es anterior a la segunda. \n");
    liberarTFecha(fecha1);
    liberarTFecha(fecha2);
}

///////////////////////////////////
/* Funciones main para Visitante */
///////////////////////////////////

void main_crearVisitante(TVisitante &visitante){
    assert(visitante == NULL);
    int id = leerInt();
    char nombre[MAX_NOMBRE];
    leerChars(nombre);
    char apellido[MAX_APELLIDO];
    leerChars(apellido);
    int edad = leerInt();
    visitante = crearTVisitante(id, nombre, apellido, edad);
    printf("Visitante creado de forma exitosa.\n");
}

void main_imprimirEdadVisitante(TVisitante visitante) {
    assert(visitante != NULL);
    printf("La edad del visitante es: %d\n", edadTVisitante(visitante));
}

void main_imprimirIdVisitante(TVisitante visitante) {
    assert(visitante != NULL);
    printf("La id del visitante es: %d\n", idTVisitante(visitante));
}

void main_imprimirNombreYApellidoVisitante(TVisitante visitante){
    assert(visitante != NULL);
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    nombreTVisitante(visitante, nombre);
    apellidoTVisitante(visitante, apellido);
    printf("El nombre del visitante es: %s\n", nombre);
    printf("El apellido del visitante es: %s\n", apellido);
}

void main_imprimirVisitante(TVisitante visitante) {
    assert(visitante != NULL);
    imprimirTVisitante(visitante);
}

void main_copiarVisitante(TVisitante visitante){
    TVisitante visitanteCopia = copiarTVisitante(visitante);
    printf("Visitante copiado. Datos de la copia:\n");
    imprimirTVisitante(visitanteCopia);

    liberarTVisitante(visitanteCopia);
}

void main_liberarVisitante(TVisitante &visitante) {
    assert(visitante != NULL);
    liberarTVisitante(visitante);
    printf("Visitante liberado con exito.\n");
}

////////////////////////////////////
//   Funciones main para Piezas   //
////////////////////////////////////
void main_crearTPieza(TPieza &pieza, TFecha &fecha){
    assert(pieza == NULL);
    int id = leerInt();
    char nombrePieza[MAX_NOMBRE_PIEZA];
    leerChars(nombrePieza);
    char nombreAutor[MAX_NOMBRE_AUTOR];
    leerChars(nombreAutor);
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    leerChars(apellidoAutor);
    pieza = crearTPieza(id, nombrePieza, nombreAutor, apellidoAutor, fecha);
    fecha = NULL;
    printf("Pieza creada en forma exitosa.\n");
}

void main_imprimirTPieza(TPieza pieza){
    assert(pieza != NULL);
    imprimirTPieza(pieza);
}

void main_liberarTPieza(TPieza &pieza){
    assert(pieza != NULL);
    liberarTPieza(pieza);
    pieza = NULL;
    printf("Pieza liberada en forma exitosa.\n");
}

void main_idTPieza(TPieza pieza){
    assert(pieza != NULL);
    int id = idTPieza(pieza);
    printf("ID: %d\n", id);
}


//////////////////////////////////////////////
//   Funciones main para Colección Piezas   //
//////////////////////////////////////////////
void main_crearColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    assert(coleccionPiezas == NULL);
    coleccionPiezas = crearColeccionPiezasVacia();
    printf("Coleccion de piezas creada de forma exitosa.\n");
}

void main_agregarColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza &pieza){
    insertarPiezaColeccionPiezas(coleccionPiezas, pieza);
    printf("Pieza agregada de forma exitosa.\n");
    pieza = NULL;
}

void main_imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    imprimirColeccionPiezas(coleccionPiezas);
}

void main_liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    liberarColeccionPiezas(coleccionPiezas);
    printf("Coleccion liberada con exito.\n");
}

void main_esVaciaColeccionPiezas(TColeccionPiezas coleccionPiezas){
    bool esVacia = esVaciaColeccionPiezas(coleccionPiezas);
    if (esVacia){
        printf("La coleccion de piezas es vacia.\n");
    } else {
        printf("La coleccion de piezas NO es vacia.\n");
    }
}

void main_existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas){
    int id = leerInt();
    bool existe = existePiezaColeccionPiezas(coleccionPiezas, id);
    if (existe){
        printf("La pieza con id %d pertenece a la coleccion.\n", id);
    } else {
        printf("La pieza con id %d NO pertenece a la coleccion.\n", id);
    }
}

void main_obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas){
    int id = leerInt();
    assert(existePiezaColeccionPiezas(coleccionPiezas, id));
    TPieza pieza = obtenerPiezaColeccionPiezas(coleccionPiezas, id);
    imprimirTPieza(pieza);
}

void main_removerDeColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    int id = leerInt();
    assert(existePiezaColeccionPiezas(coleccionPiezas, id));
    removerPiezaColeccionPiezas(coleccionPiezas, id);
    printf("Pieza con id %d removida con exito.\n", id);
}


////////////////////////////////
/* Funciones main para Grupo */
////////////////////////////////

void main_crearGrupoABB(TGrupoABB &grupo, int &generadorID){
    assert(grupo == NULL);
    generadorID++;
    grupo = crearTGrupoABBVacio(generadorID);
    printf("El grupoABB ha sido creado de forma exitosa.\n");
}

void main_agregarVisitanteAGrupoABB(TGrupoABB &grupo, TVisitante &visitante){
    assert(visitante != NULL);
    insertarTVisitanteTGrupoABB(grupo, visitante);
    visitante = NULL;
    printf("Se ha agregado el visitante al grupo de forma exitosa.\n");
}

void main_imprimirGrupoABB(TGrupoABB grupo){
    imprimirTGrupoABB(grupo);
}

void main_liberarGrupoABB(TGrupoABB &grupo){
    liberarTGrupoABB(grupo);
    printf("Grupo liberado con exito.\n");
}

void main_existeEnGrupoABB(TGrupoABB grupo){
    int id = leerInt();
    if (existeTVisitanteTGrupoABB(grupo, id)){
        printf("El visitante con id %d pertenece al grupo.\n", id);
    }else{
        printf("El visitante con id %d NO pertenece al grupo.\n", id);
    }
}

void main_obtenerVisitanteGrupoABB(TGrupoABB grupo){
    int id = leerInt();
    TVisitante visitante = obtenerTVisitanteTGrupoABB(grupo, id);
    if (visitante == NULL){
        printf("El visitante con id %d no se puede imprimir pues NO pertenece al grupo.\n", id);
    }else{  
        imprimirTVisitante(visitante);
    }
}

void main_alturaGrupoABB(TGrupoABB grupo){
    nat altura = alturaTGrupoABB(grupo);
    printf("La altura del grupo es %d.\n", altura);
}

void main_maxIdGrupoABB(TGrupoABB grupo){
    TVisitante maxId = maxIdTVisitanteTGrupoABB(grupo);
    printf("El mayor id en el grupo es %d.\n", idTVisitante(maxId));
}

void main_cantidadVisitantesGrupoABB(TGrupoABB grupo){
    int cantidad = cantidadVisitantesTGrupoABB(grupo);
    printf("La cantidad de visitantes en el grupo es %d.\n", cantidad);
}

void main_edadPromedioGrupoABB(TGrupoABB grupo){
    float edadPromedio = edadPromedioTGrupoABB(grupo);
    printf("La edad promedio del grupo es %.2f.\n", edadPromedio);
}

void main_removerDeGrupoABB(TGrupoABB &grupo){
    int id = leerInt();
    if (existeTVisitanteTGrupoABB(grupo, id)) {
        removerTVisitanteTGrupoABB(grupo, id);
        printf("El visitante con id %d se removio del grupo.\n", id);
    } else {
        printf("El visitante con id %d no se puede remover porque NO pertenece al grupo.\n", id);
    }
}

void main_obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupo){
    int n = leerInt();
    int cantEnGrupo = cantidadVisitantesTGrupoABB(grupo); 
    if (cantEnGrupo >= n) {
        TVisitante visitante = obtenerNesimoVisitanteTGrupoABB(grupo, n);
        printf("Visitante nro %d del grupoABB:\n", n);
        imprimirTVisitante(visitante);
    } else {
        printf("No se puede imprimir vistante %d del grupoABB porque tiene solo %d visitantes.\n", n, cantEnGrupo);
    }
}

void insertarEnArbolDesdeArreglo(TGrupoABB &grupoABB, TVisitante *arreglo, int inicio, int final){
    if (inicio <= final){
        int mid = (inicio + final) / 2;
        insertarTVisitanteTGrupoABB(grupoABB, arreglo[mid]);
        insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, mid - 1);
        insertarEnArbolDesdeArreglo(grupoABB, arreglo, mid + 1, final);
    }
}

void main_alturaGrupoABBTiempo(int &generadorID){
    generadorID++;
    TGrupoABB grupoABB = crearTGrupoABBVacio(generadorID);

    nat tamanio = leerNat();
    nat timeout = leerNat();

    TVisitante *arreglo = new TVisitante[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTVisitante(i, "Alberto", "Pardo", 52);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, final);
    clock_t tm = clock();
    nat altura = alturaTGrupoABB(grupoABB);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    }else{
        printf("La altura del grupo es %d. Calculado correctamente en menos de %ds.\n", altura, timeout);    
    }
    
    liberarTGrupoABB(grupoABB);
    delete[] arreglo;
}

void main_obtenerExisteVisitanteGrupoABBTiempo(int &generadorID){
    generadorID++;
    TGrupoABB grupoABB = crearTGrupoABBVacio(generadorID);

    nat tamanio = leerNat();
    double timeout = leerDouble();

    TVisitante *arreglo = new TVisitante[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTVisitante(i, "Carlos", "Luna", 45);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDesdeArreglo(grupoABB, arreglo, inicio, final);
    clock_t tm = clock();
    bool existeVisitante1 = existeTVisitanteTGrupoABB(grupoABB, 0);
    bool existeVisitante2 = existeTVisitanteTGrupoABB(grupoABB, tamanio - 1);
    bool existeVisitante3 = existeTVisitanteTGrupoABB(grupoABB, tamanio / 3);
    bool existeVisitante4 = existeTVisitanteTGrupoABB(grupoABB, (2 * tamanio) / 3);
    TVisitante visitante1 = obtenerTVisitanteTGrupoABB(grupoABB, 0);
    TVisitante visitante2 = obtenerTVisitanteTGrupoABB(grupoABB, tamanio - 1);
    TVisitante visitante3 = obtenerTVisitanteTGrupoABB(grupoABB, tamanio / 3);
    TVisitante visitante4 = obtenerTVisitanteTGrupoABB(grupoABB, (2 * tamanio) / 3);
    tm = clock() - tm;

    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    if (tiempo > timeout){
        printf("ERROR, tiempo excedido: %.3f > %.3f \n", tiempo, timeout);
    }else{
        printf("Se obtuvieron los visitantes? %d %d %d %d con ids respectivos %d %d %d %d\n", existeVisitante1, existeVisitante2, existeVisitante3, existeVisitante4, idTVisitante(visitante1), idTVisitante(visitante2), idTVisitante(visitante3), idTVisitante(visitante4));
        printf("Calculado correctamente en menos de %.3fs.\n", timeout);    
    }
    
    liberarTGrupoABB(grupoABB);
    delete[] arreglo;
}

//////////////////////////////////////////
// Funciones main para ColeccionTGrupos //
//////////////////////////////////////////
void main_crearColeccionGrupos(TColeccionTGrupos &coleccion){
    assert(coleccion == NULL);
    coleccion = crearTColeccionTGruposVacia();
    printf("La coleccion de grupos ha sido creado de forma exitosa.\n");
}

void main_agregarGrupoAColeccion(TColeccionTGrupos &coleccion, TGrupoABB &grupo){
    assert(grupo != NULL);
    insertarGrupoTColeccionTGrupos(coleccion, grupo);
    grupo = NULL;
    printf("Se ha agregado el grupo a la coleccion de forma exitosa.\n");
}

void main_imprimirColeccionTGrupos(TColeccionTGrupos coleccion){
    imprimirTColeccionTGrupos(coleccion);
}

void main_imprimirColeccionInvertidaTGrupos(TColeccionTGrupos coleccion){
    imprimirInvertidoTColeccionTGrupos(coleccion);
}

void main_obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccion){
    int n = leerInt();
    TGrupoABB grupo = obtenerNesimoColeccionTGrupos(coleccion, n);
    if (grupo){
        printf("Grupo en la posicion %d:\n", n);
        imprimirTGrupoABB(grupo);
    }else{
        printf("NO existe un grupo en la posicion %d\n", n);
    }
}

void main_cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccion){
    nat cant = cantidadTGruposColeccionTGrupos(coleccion);
    printf("La cantidad de grupos en la coleccion es %d\n", cant);
}

void main_obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccion){
    nat cant = cantidadTGruposColeccionTGrupos(coleccion);
    if (cant > 0){
        TGrupoABB grupo = obtenerPrimeroColeccionTGrupos(coleccion);
        assert(grupo != NULL);
        printf("Primer grupo:\n");
        imprimirTGrupoABB(grupo);
    }else{
        printf("No se puede obtener el primero de la coleccion de grupos porque es vacia\n");
    }
}

void main_removerUltimoColeccionTGrupos(TColeccionTGrupos coleccion){
    nat cant = cantidadTGruposColeccionTGrupos(coleccion);
    if (cant > 0){
        TGrupoABB grupo = removerUltimoColeccionTGrupos(coleccion);
        assert(grupo != NULL);
        printf("Ultimo grupo (removido):\n");
        imprimirTGrupoABB(grupo);
        liberarTGrupoABB(grupo);
    }else{
        printf("No se puede remover el ultimo de la coleccion de grupos porque es vacia\n");
    }
}

void main_removerNesimoColeccionTGrupos(TColeccionTGrupos coleccion){
    nat n = leerNat();
    nat cant = cantidadTGruposColeccionTGrupos(coleccion);
    if (cant >= n){
        TGrupoABB grupo = removerNesimoColeccionTGrupos(coleccion, n);
        assert(grupo != NULL);
        printf("Grupo en la posicion %d (removido):\n", n);
        imprimirTGrupoABB(grupo);
        liberarTGrupoABB(grupo);
    }else{
        printf("No se puede remover el elemento %d de la coleccion de grupos porque solo contiene %d\n", n, cant);
    }
}

void main_liberarColeccionTGrupos(TColeccionTGrupos &coleccion){
    assert(coleccion != NULL);
    liberarTColeccionTGrupos(coleccion);
    printf("Coleccion de grupos liberada\n");
    coleccion = NULL;
}

void main_obtenerVisitantesRepetidos(TColeccionTGrupos coleccion){
    assert(coleccion != NULL);
    TGrupoABB grupo = obtenerVisitantesRepetidos(coleccion);
    if (cantidadVisitantesTGrupoABB(grupo) == 0){
        printf("No hay visitantes repetidos entre los grupos.\n");
    }else{
        printf("Los visitantes repetidos son:\n");
        imprimirTGrupoABB(grupo);
    }
    liberarTGrupoABB(grupo);
}

void main_visitanteMasRepetido(TColeccionTGrupos coleccion){
    assert(coleccion != NULL);
    TVisitante visitante = visitanteMasRepetido(coleccion);
    if (visitante == NULL){
        printf("No hay visitante repetido porque no hay visitantes en los grupos de la coleccion.\n");
    }else{
        printf("El visitante que aparece en la mayor cantidad de grupos es:\n");
        imprimirTVisitante(visitante);
    }
}


///////////////////////////////////
// Funciones main para VisitaDia //
///////////////////////////////////
void main_crearVisitaDia(TVisitaDia &visitaDia){
    TFecha fecha = NULL;
    leerFecha(fecha);

    assert(visitaDia == NULL);    
    visitaDia = crearTVisitaDia(fecha, MAX_GRUPOS_VISITA_DIA);
    printf("La visita dia se ha creado de forma exitosa.\n");
}

void main_imprimirVisitaDia(TVisitaDia &visitaDia){
    imprimirTVisitaDia(visitaDia);
}

void main_encolarGrupoVisitaDia(TVisitaDia &visitaDia, TGrupoABB &grupo){
    assert(grupo != NULL);
    encolarGrupoTVisitaDia(visitaDia, grupo);
    grupo = NULL;
    printf("Se ha agregado el grupo a la visita dia de forma exitosa.\n");
}

void main_cantidadGruposVisitaDia(TVisitaDia visitaDia){
    int cant = cantidadGruposTVisitaDia(visitaDia);
    printf("La cantidad de grupos en la visita dia es %d\n", cant);
}

void main_desencolarGrupoVisitaDia(TVisitaDia &visitaDia){
    assert(visitaDia != NULL);
    TGrupoABB grupo = desencolarGrupoTVisitaDia(visitaDia);
    imprimirTGrupoABB(grupo);
    liberarTGrupoABB(grupo);
}

void main_liberarVisitaDia(TVisitaDia &visitaDia){
    assert(visitaDia != NULL);
    liberarTVisitaDia(visitaDia);
    assert(visitaDia == NULL);
    printf("La visita dia se ha liberado exitosamente.\n");
    visitaDia = NULL;
}

void main_invertirPrioridadTVisitaDia(TVisitaDia &visitaDia){
    assert(visitaDia != NULL);
    invertirPrioridadTVisitaDia(visitaDia);
    printf("Se ejecuto invertirPrioridadTVisitaDia exitosamente.\n");
}

void main_estaEnTVisitaDia(TVisitaDia visitaDia){
    assert(visitaDia != NULL);

    int idGrupo = leerInt();
    bool esta = estaEnTVisitaDia(visitaDia, idGrupo);
    if (esta){
        printf("El grupo de id %d pertenece a la visitaDia.\n", idGrupo);
    }else{
        printf("El grupo de id %d NO pertenece a la visitaDia.\n", idGrupo);
    }
}

void main_prioridadTVisitaDia(TVisitaDia visitaDia){
    assert(visitaDia != NULL);
    int idGrupo = leerInt();
    float prioridad = prioridadTVisitaDia(visitaDia, idGrupo);
    printf("La prioridad del grupo de id %d es %.2f .\n", idGrupo, prioridad);
}

void main_maxGruposTVisitaDia(TVisitaDia visitaDia){
    assert(visitaDia != NULL);
    int maxGrupos = maxGruposTVisitaDia(visitaDia);
    printf("Pueden existir %d max grupos en la visitaDia.\n", maxGrupos);
}

void main_fechaTVisitaDia(TVisitaDia visitaDia){
    assert(visitaDia != NULL);
    TFecha fecha = fechaTVisitaDia(visitaDia);
    printf("La visitaDia corresponde a la fecha: ");
    imprimirTFecha(fecha);
    printf("\n");
}

void main_masPrioritarioTVisitaDia(TVisitaDia visitaDia){
    assert(visitaDia != NULL);
    TGrupoABB grupo = masPrioritarioTVisitaDia(visitaDia);
    printf("El grupo con mayor prioridad de la visitaDia es:\n");
    imprimirTGrupoABB(grupo);
}


///////////////////////////////////
//        Conjunto Piezas        //
///////////////////////////////////
void main_crearConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas){
    assert(conjuntoPiezas == NULL);

    int cantMax = leerInt();    
    conjuntoPiezas = crearTConjuntoPiezas(cantMax);
    printf("El conjunto piezas fue creado en forma correcta.\n");
}

void main_esVacioConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    bool esVacia = esVacioTConjuntoPiezas(conjuntoPiezas);
    if (esVacia){
        printf("El conjunto de piezas es vacio.\n");
    } else {
        printf("La conjunto de piezas NO es vacio.\n");
    }
}

void main_insertarConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas){
    int id = leerInt();
    insertarTConjuntoPiezas(conjuntoPiezas, id);
    printf("Se ejecuto 'insertarTConjuntoPiezas' con pieza de id %d exitosamente.\n", id);
}

void main_borrarDeConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas){
    int id = leerInt();
    borrarDeTConjuntoPiezas(conjuntoPiezas, id);
    printf("Se ejecuto 'borrarDeTConjuntoPiezas' con pieza de id %d exitosamente.\n", id);    
}

void main_perteneceConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int id = leerInt();
    bool pertenece = perteneceTConjuntoPiezas(conjuntoPiezas, id);
    if (pertenece){
        printf("La pieza de id %d pertenece al conjunto.\n", id);   
    }else{
        printf("La pieza de id %d NO pertenece al conjunto.\n", id);   
    }
}

void main_cardinalConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int cardinal = cardinalTConjuntoPiezas(conjuntoPiezas);
    printf("El cardinal del conjunto es: %d.\n", cardinal);    
}

void main_cantMaxConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int cantMax = cantMaxTConjuntoPiezas(conjuntoPiezas);
    printf("La cantidad maxima del conjunto es: %d.\n", cantMax);    
}

void main_imprimirConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    printf("Conjunto de piezas:\n");    
    imprimirTConjuntoPiezas(conjuntoPiezas);
}

void main_liberarConjuntoPiezas(TConjuntoPiezas &conjuntoPiezas){
    liberarTConjuntoPiezas(conjuntoPiezas);
    printf("Conjunto de piezas liberado exitosamente.\n");
}

void main_unionConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int cantMax = cantMaxTConjuntoPiezas(conjuntoPiezas);
    TConjuntoPiezas otroConjunto = crearTConjuntoPiezas(cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int id = leerInt();
        insertarTConjuntoPiezas(otroConjunto, id);
    }

    TConjuntoPiezas unionConjuntoPiezas = unionTConjuntoPiezas(conjuntoPiezas, otroConjunto);
    printf("Conjunto de piezas union:\n");    
    imprimirTConjuntoPiezas(unionConjuntoPiezas);

    liberarTConjuntoPiezas(unionConjuntoPiezas);
    liberarTConjuntoPiezas(otroConjunto);
}

void main_interseccionConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int cantMax = cantMaxTConjuntoPiezas(conjuntoPiezas);
    TConjuntoPiezas otroConjunto = crearTConjuntoPiezas(cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int id = leerInt();
        insertarTConjuntoPiezas(otroConjunto, id);
    }

    TConjuntoPiezas interseccion = interseccionTConjuntoPiezas(conjuntoPiezas, otroConjunto);
    printf("Conjunto de piezas interseccion:\n");    
    imprimirTConjuntoPiezas(interseccion);

    liberarTConjuntoPiezas(interseccion);
    liberarTConjuntoPiezas(otroConjunto);
}

void main_diferenciaConjuntoPiezas(TConjuntoPiezas conjuntoPiezas){
    int cantMax = cantMaxTConjuntoPiezas(conjuntoPiezas);
    TConjuntoPiezas otroConjunto = crearTConjuntoPiezas(cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int id = leerInt();
        insertarTConjuntoPiezas(otroConjunto, id);
    }

    TConjuntoPiezas diferencia = diferenciaTConjuntoPiezas(conjuntoPiezas, otroConjunto);
    printf("Conjunto de piezas diferencia:\n");    
    imprimirTConjuntoPiezas(diferencia);

    liberarTConjuntoPiezas(diferencia);
    liberarTConjuntoPiezas(otroConjunto);
}


///////////////////////////////////
//          Exposicion           //
///////////////////////////////////
void main_crearExposicion(TExposicion &expo){
    assert(expo == NULL);

    TFecha fechaIni;
    leerFecha(fechaIni);

    TFecha fechaFin;
    leerFecha(fechaFin);

    int cantMax = leerInt();
    int id = leerInt();

    expo = crearTExposicion(id, fechaIni, fechaFin, cantMax);
    printf("Exposicion creada con exito.\n");
}

void main_agregarAExposicion(TExposicion expo){
    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int idPieza = leerInt();

        TFecha fechaDummy = crearTFecha(1,1,1);
        TPieza p = crearTPieza(idPieza, NOMBRE_PIEZA_DUMMY, NOMBRE_AUTOR_PIEZA_DUMMY, APELLIDO_AUTOR__PIEZA_DUMMY, fechaDummy);
        agregarATExposicion(expo, p);
        liberarTPieza(p);
    }

    printf("Piezas agregadas a la exposicion de forma exitosa.\n");
}

void main_perteneceAExposicion(TExposicion expo){
    int idPieza = leerInt();

    TFecha fechaDummy = crearTFecha(1,1,1);
    TPieza p = crearTPieza(idPieza, NOMBRE_PIEZA_DUMMY, NOMBRE_AUTOR_PIEZA_DUMMY, APELLIDO_AUTOR__PIEZA_DUMMY, fechaDummy);
    bool pertenece = perteneceATExposicion(expo, p);

    if (pertenece){
        printf("La pieza de id %d pertenece a la exposicion.\n", idTPieza(p));
    }else{
        printf("La pieza de id %d NO pertenece a la exposicion.\n", idTPieza(p));
    }

    liberarTPieza(p);
}

void main_idExposicion(TExposicion expo){
    printf("El id de la exposicion es: %d.\n", idTExposicion(expo));
}

void main_fechaInicioTExposicion(TExposicion expo){
    printf("La fecha inicio de la exposicion es: ");
    TFecha fechaIni = fechaInicioTExposicion(expo);
    imprimirTFecha(fechaIni);
    printf("\n");
}

void main_fechaFinTExposicion(TExposicion expo){
    printf("La fecha fin de la exposicion es: ");
    TFecha fechaFin = fechaFinTExposicion(expo);
    imprimirTFecha(fechaFin);
    printf("\n");
}

void main_imprimirExposicion(TExposicion expo){
    imprimirTExposicion(expo);
}

void main_sonExposicionesCompatibles(TExposicion expo1){
    TFecha fechaIni;
    leerFecha(fechaIni);

    TFecha fechaFin;
    leerFecha(fechaFin);

    int cantMax = leerInt();
    int id = leerInt();

    TExposicion expo2 = crearTExposicion(id, fechaIni, fechaFin, cantMax);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int idPieza = leerInt();

        TFecha fechaDummy = crearTFecha(1,1,1);
        TPieza p = crearTPieza(idPieza, NOMBRE_PIEZA_DUMMY, NOMBRE_AUTOR_PIEZA_DUMMY, APELLIDO_AUTOR__PIEZA_DUMMY, fechaDummy);
        agregarATExposicion(expo2, p);
        liberarTPieza(p);
    }

    if (sonExposicionesCompatibles(expo1, expo2)){
        printf("Las exposiciones son compatibles.\n");
    }else{
        printf("Las exposiciones NO son compatibles.\n");
    }

    liberarTExposicion(expo2);
}

void main_liberarTExposicion(TExposicion &expo){
    liberarTExposicion(expo);
    printf("Exposicion liberada con exito.\n");
}


///////////////////////////////////
//       Lista Exposiciones      //
///////////////////////////////////
void main_crearListaExposiciones(TListaExposiciones &listaExpo){
    assert(listaExpo == NULL);

    listaExpo = crearTListaExposicionesVacia();
    printf("Lista de exposiciones creada con exito.\n");
}

void main_agregarAListaExposiciones(TListaExposiciones &listaExpo, TExposicion &expo){
    assert(expo != NULL);
    agregarExposicionTListaExposiciones(listaExpo, expo);
    expo = NULL;
    printf("Se ha agregado la exposicion a la lista de forma exitosa.\n");
}

void main_esVaciaListaExposiciones(TListaExposiciones listaExpo){
    bool esVacia = esVaciaTListaExposiciones(listaExpo);
    if (esVacia){
        printf("La lista de exposiciones es vacia..\n");
    }else{
        printf("La lista de exposiciones NO es vacia.\n");
    }
}

void main_imprimirListaExposiciones(TListaExposiciones listaExpo){
    imprimirTListaExposiciones(listaExpo);
}

void main_liberarListaExposiciones(TListaExposiciones &listaExpo){
    liberarTListaExposiciones(listaExpo, true);
    printf("Lista exposiciones liberada con exito.\n");
}


void main_perteneceExposicionListaExposiciones(TListaExposiciones listaExposiciones){
    int idExpo = leerInt();

    bool pertenece = perteneceExposicionTListaExposiciones(listaExposiciones, idExpo);
    if (pertenece){
        printf("La exposicion de id %d pertenece a la lista de exposiciones.\n", idExpo);
    }else{
        printf("La exposicion de id %d NO pertenece a la lista de exposiciones.\n", idExpo);
    }
}

void main_obtenerExposicionListaExposiciones(TListaExposiciones listaExposiciones){
    int idExpo = leerInt();

    bool pertenece = perteneceExposicionTListaExposiciones(listaExposiciones, idExpo);
    if (pertenece){
        TExposicion expo = obtenerExposicionTListaExposiciones(listaExposiciones, idExpo);
        imprimirTExposicion(expo);
    }else{
        printf("La exposicion de id %d NO pertenece a la lista de exposiciones.\n", idExpo);
    }
}


void main_obtenerExposicionesFinalizadas(TListaExposiciones &listaExpo){
    TFecha fecha;
    leerFecha(fecha);

    TListaExposiciones finalizadas = obtenerExposicionesFinalizadas(listaExpo, fecha);

    printf("Exposiciones finalizadas: \n");
    imprimirTListaExposiciones(finalizadas);
    liberarTListaExposiciones(finalizadas, true);
    liberarTFecha(fecha);
}

void main_obtenerExposicionesActivas(TListaExposiciones &listaExpo){
    TFecha fecha;
    leerFecha(fecha);

    TListaExposiciones activas = obtenerExposicionesActivas(listaExpo, fecha);

    printf("Exposiciones activas: \n");
    imprimirTListaExposiciones(activas);
    liberarTListaExposiciones(activas, true);
    liberarTFecha(fecha);
}

void main_esCompatibleListaExposiciones(TListaExposiciones listaExpo, TExposicion expo){
    bool compatible = esCompatibleTListaExposiciones(listaExpo, expo);
    
    if (compatible){
        printf("La exposicion es compatible con el resto de las exposiciones de la lista.\n");
    }else{
        printf("La exposicion NO es compatible con el resto de las exposiciones de la lista.\n");
    }
}

void main_unirListaExposiciones(TListaExposiciones listaExpo){
    TListaExposiciones lista2 = crearTListaExposicionesVacia();
    int cantidadExposiciones = leerInt();
    for (int i=0; i < cantidadExposiciones; i++){
        TFecha fechaInicio = NULL;
        leerFecha(fechaInicio);
        TFecha fechaFin = NULL;
        leerFecha(fechaFin);
        int cantidadPiezas = leerInt();
        int idExpo = leerInt();
        TExposicion expo = crearTExposicion(idExpo, fechaInicio, fechaFin, cantidadPiezas);
        int cantidadPiezasAgregar = leerInt();
        for (int i = 0; i < cantidadPiezasAgregar; i++){
            int idPieza = leerInt();

            TFecha fechaDummy = crearTFecha(1,1,1);
            TPieza p = crearTPieza(idPieza, NOMBRE_PIEZA_DUMMY, NOMBRE_AUTOR_PIEZA_DUMMY, APELLIDO_AUTOR__PIEZA_DUMMY, fechaDummy);
            agregarATExposicion(expo, p);
            liberarTPieza(p);
        } 
        agregarExposicionTListaExposiciones(lista2, expo);
    }
    TListaExposiciones unida = unirListaExposiciones(listaExpo, lista2);
    imprimirTListaExposiciones(unida);
    liberarTListaExposiciones(unida, false);
    liberarTListaExposiciones(lista2, true);
}


///////////////////////////////////
//             Galeria           //
///////////////////////////////////
void main_crearGaleria(TGaleria &galeria){
    assert(galeria == NULL);

    TFecha fechaActual;
    leerFecha(fechaActual);

    galeria = crearTGaleria(fechaActual);
    printf("Galeria creada con exito.\n");
}

void main_agregarPiezaGaleria(TGaleria galeria, TPieza &pieza){
    agregarPiezaTGaleria(galeria, pieza);
    pieza = NULL;
    printf("La pieza fue agregada a la galeria con exito.\n");
}

void main_agregarExposicionGaleria(TGaleria galeria, TExposicion &expo){
    agregarExposicionTGaleria(galeria, expo);
    expo = NULL;
    printf("La exposicion fue agregada a la galeria con exito.\n");    
}

void main_agregarPiezaAExposicionGaleria(TGaleria galeria){
    int idPieza = leerInt();
    int idExpo = leerInt();

    agregarPiezaAExposicionTGaleria(galeria, idPieza, idExpo);
    printf("La pieza de id %d fue agregada a la exposicion de id %d.\n", idPieza, idExpo);    
}

void main_avanzarAFechaGaleria(TGaleria galeria){
    TFecha fecha;
    leerFecha(fecha);
    avanzarAFechaTGaleria(galeria, fecha);    
    printf("Se avanzo la fecha de la galeria a ");
    imprimirTFecha(fecha);    
    printf("\n");    
}

void main_imprimirExposicionesFinalizadasGaleria(TGaleria galeria){
    printf("Exposiciones finalizadas:\n");
    imprimirExposicionesFinalizadasTGaleria(galeria);    
}

void main_imprimirExposicionesActivasGaleria(TGaleria galeria){
    printf("Exposiciones activas:\n");
    imprimirExposicionesActivasTGaleria(galeria);    
}

void main_imprimirExposicionesFuturasGaleria(TGaleria galeria){
    printf("Exposiciones futuras:\n");
    imprimirExposicionesFuturasTGaleria(galeria);
}

void main_esCompatibleExposicionGaleria(TGaleria galeria, TExposicion expo){
    bool esCompatible = esCompatibleExposicionTGaleria(galeria, expo);
    if (esCompatible){
        printf("La exposicion es compatible con las demas exposiciones de la galeria.\n");
    } else {
        printf("La exposicion NO es compatible con las demas exposiciones de la galeria.\n");
    }
}

void main_liberarGaleria(TGaleria &galeria){
    liberarTGaleria(galeria);
    printf("Galeria liberada con exito.\n");
}

void main_llegaGrupoTGaleria(TGaleria galeria, TGrupoABB &grupo){
    assert(galeria != NULL);
    llegaGrupoTGaleria(galeria, grupo);
    printf("Se ejecuto llegaGrupoTGaleria con exito.\n");

    grupo = NULL;
}

void main_obtenerVisitaDiaTGaleria(TGaleria galeria){
    assert(galeria != NULL);

    TFecha fecha;
    leerFecha(fecha);

    TVisitaDia visitaDia = obtenerVisitaDiaTGaleria(galeria, fecha);
    if (visitaDia == NULL){
       printf("No existen registros de visitaDia para la fecha ");
       imprimirTFecha(fecha);
       printf("\n");
    }else{
        imprimirTVisitaDia(visitaDia);
    }

    liberarTFecha(fecha);
}

void main_piezasEnExposicionTGaleria(TGaleria galeria){
    assert(galeria != NULL);

    TConjuntoPiezas piezasEnExposicion = piezasEnExposicionTGaleria(galeria);
    printf("Las piezas en exposicion en la galeria son:\n");
    imprimirTConjuntoPiezas(piezasEnExposicion);
    liberarTConjuntoPiezas(piezasEnExposicion);
}

void main_indiceFelicidadVisitanteTGaleria(TGaleria galeria, TVisitante visitante){
    assert(galeria != NULL);

    float felicidad = indiceFelicidadVisitanteTGaleria(galeria, visitante);
    printf("El indice de felicidad del visitante es %.2f\n", felicidad);
}

void main_piezasEnReservaTGaleria(TGaleria galeria){
    assert(galeria != NULL);

    TConjuntoPiezas piezasEnReserva = piezasEnReservaTGaleria(galeria);
    printf("Las piezas en reserva en la galeria son:\n");
    imprimirTConjuntoPiezas(piezasEnReserva);
    liberarTConjuntoPiezas(piezasEnReserva);
}



//////////////////////////////////
//        Hash Visita Dia       //
//////////////////////////////////
void main_crearTHashVisitaDia(THashVisitaDia &hash){
    assert(hash == NULL);
    int cantEstimada = leerInt();
    hash = crearTHashVisitaDia(cantEstimada);
    printf("Hash creado exitosamente.\n");
}

void main_agregarVisitaDiaTHashVisitaDia(THashVisitaDia hash, TVisitaDia &visitaDia){
    assert(hash != NULL);
    agregarVisitaDiaTHashVisitaDia(hash, visitaDia);
    printf("Visita dia agregada al hash exitosamente.\n");

    visitaDia = NULL;
}

void main_imprimirTHashVisitaDia(THashVisitaDia hash){
    assert(hash != NULL);
    imprimirTHashVisitaDia(hash);
}

void main_obtenerVisitaDiaTHashVisitaDia(THashVisitaDia hash){
    assert(hash != NULL);

    TFecha fecha;
    leerFecha(fecha);
    TVisitaDia visitaDia = obtenerVisitaDiaTHashVisitaDia(hash, fecha);
    if (visitaDia == NULL){
        printf("No se puede obtener la visitaDia de fecha ");
        imprimirTFecha(fecha);
        printf(" porque NO pertenece al hash.\n");
    }else{
        imprimirTVisitaDia(visitaDia);        
    }
    liberarTFecha(fecha);
}

void main_perteneceVisitaDiaTHashVisitaDia(THashVisitaDia hash){
    assert(hash != NULL);

    TFecha fecha;
    leerFecha(fecha);
    bool pertenece = perteneceVisitaDiaTHashVisitaDia(hash, fecha);

    printf("La visitaDia de fecha ");
    imprimirTFecha(fecha);
    if (pertenece){
        printf(" pertenece al hash.\n");
    }else{
        printf(" NO pertenece al hash.\n");
    }
    liberarTFecha(fecha);
}

void main_liberarTHashVisitaDia(THashVisitaDia &hash){
    assert(hash != NULL);
    liberarTHashVisitaDia(hash);
    printf("Hash liberado con exito.\n");
}

// AGREGADOS TAREA 4

void main_agregarPiezasFavoritasTVisitante(TVisitante visitante){
    assert(visitante != NULL);

    int cant = leerInt();
    for (int i = 0; i < cant; i++){
        int idPieza = leerInt();
        agregarPiezaFavoritaTVisitante(visitante, idPieza);
    }

    printf("Se ejecuto agregarPiezasFavoritasTVisitante exitosamente.\n");
}

void main_obtenerPiezasFavoritasTVisitante(TVisitante visitante){
    assert(visitante != NULL);

    TConjuntoPiezas piezasFavoritas = obtenerPiezasFavoritasTVisitante(visitante);
    printf("Piezas favoritas del visitante:\n");
    imprimirTConjuntoPiezas(piezasFavoritas);
}

void main_cantidadExposicionesTListaExposiciones(TListaExposiciones listaExpo){
    int cantExpo = cantidadExposicionesTListaExposiciones(listaExpo);
    printf("Hay %d exposiciones en la lista de exposiciones.\n", cantExpo);
}

void main_obtenerNesimaExposicionTListaExposiciones(TListaExposiciones listaExpo){
    int n = leerInt();

    TExposicion expo = obtenerNesimaExposicionTListaExposiciones(listaExpo, n);
    printf("Exposicion en posicion %d de la lista:\n", n);
    imprimirTExposicion(expo);
}

void main_obtenerPiezasTExposicion(TExposicion expo){
    assert(expo != NULL);
    
    TConjuntoPiezas piezasExpo = obtenerPiezasTExposicion(expo);
    printf("Las piezas de la exposicion son las siguientes:\n");
    imprimirTConjuntoPiezas(piezasExpo);
}

void main_testTiempoVisitaDia(){
    printf("Comienzo de test de tiempo para Visita Dia.\n");
    TFecha fecha = crearTFecha(1,1,2001);
    int cantidadGrupos = leerNat();
    double timeoutEncolar = leerDouble();
    double timeoutDesencolar = leerDouble();
    double timeoutCantidadGrupos = leerDouble();
    clock_t tm = clock();
    TVisitaDia visitaDia = crearTVisitaDia(fecha,cantidadGrupos);
    for(int i = 1; i <= cantidadGrupos; i++){
        TVisitante visitante = crearTVisitante(1, "Nombre", "Apellido", cantidadGrupos - i + 1);
        TGrupoABB grupo = crearTGrupoABBVacio(i);
        insertarTVisitanteTGrupoABB(grupo, visitante);
        encolarGrupoTVisitaDia(visitaDia, grupo);
    }
    tm = clock() - tm;
    double tiempo = ((double)tm) / CLOCKS_PER_SEC;
    assert(tiempo < timeoutEncolar);
    tm = clock();
    int cantidadGruposInsertados = cantidadGruposTVisitaDia(visitaDia);
    tm = clock() - tm;
    tiempo = ((double)tm) / CLOCKS_PER_SEC;
    assert(tiempo < timeoutCantidadGrupos);
    assert(cantidadGrupos == cantidadGruposInsertados);
    tm = clock();
    for(int i = 1; i <= cantidadGrupos; i++){
        TGrupoABB grupo = desencolarGrupoTVisitaDia(visitaDia);
        assert(edadPromedioTGrupoABB(grupo) == i);
        liberarTGrupoABB(grupo);
    }    
    liberarTVisitaDia(visitaDia);
    tm = clock() - tm;
    tiempo = ((double)tm) / CLOCKS_PER_SEC;
    assert(tiempo < timeoutDesencolar);
    printf("Fin de test de tiempo para Visita Dia.\n");
}

void main_testTiempoHashVisitaDia(){
    printf("Comienzo de test de tiempo para Hash Visita Dia.\n");
    double cantidad = leerInt();
    int timeoutAgregar = leerNat();
    THashVisitaDia hashVisitaDia = crearTHashVisitaDia(cantidad);
    TFecha fecha = crearTFecha(1, 1, 2001);
    TFecha copiaFecha = NULL;
    clock_t tm = clock();
    for(int i = 0; i < cantidad; i++){
        TVisitaDia visitaDia = crearTVisitaDia(fecha, 1);
        agregarVisitaDiaTHashVisitaDia(hashVisitaDia, visitaDia);
        copiaFecha = copiarTFecha(fecha);
        aumentarTFecha(copiaFecha, 1);
        fecha = copiaFecha;
    }
    liberarTFecha(fecha);
    fecha = NULL;
    copiaFecha = NULL;
    tm = clock() - tm;
    double tiempo = ((double)tm) / CLOCKS_PER_SEC;
    assert(tiempo < timeoutAgregar);
    for(int i = 0; i < cantidad; i++){
        
    }
    liberarTHashVisitaDia(hashVisitaDia);
    printf("Fin de test de tiempo para Hash Visita Dia.\n");
}

