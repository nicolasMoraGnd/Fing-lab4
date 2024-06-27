#include "../include/fecha.h"

// Estructura para almacenar una fecha con día, mes y año
struct rep_fecha {
    nat dia, mes, anio;
};

// Función para crear un nuevo objeto de tipo TFecha con una fecha dada
TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    return nuevaFecha;
}

// Función para liberar un objeto de tipo TFecha previamente creado
void liberarTFecha(TFecha &fecha) {
    delete fecha;
    fecha = NULL;
}

// Función para determinar si un año es bisiesto
bool esBisiesto(nat anio) {
    if (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0)) {
        return true;
    }
    return false;
}

// Función para obtener la cantidad de días de un mes en un año dado
nat diasMes(nat mes, nat anio) {
    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (esBisiesto(anio)) {
                return 29;
            }
            return 28;
        default:
            return 0;
    }
}

// Función para aumentar una fecha en una cantidad dada de días
void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

TFecha copiarTFecha(TFecha fecha){
    TFecha copia = new rep_fecha;
    copia->dia = fecha->dia;
    copia->mes = fecha->mes;
    copia->anio = fecha->anio;
    return copia;
}

int sgn(int val) {
    return (int(0) < val) - (val < int(0));
}

// Función para comparar dos fechas representadas por objetos de tipo TFecha
int compararTFechas(TFecha fecha1, TFecha fecha2) {
    if (fecha1->anio != fecha2->anio) {
        return sgn((int)fecha1->anio - (int)fecha2->anio);
    }
    if (fecha1->mes != fecha2->mes) {
        return sgn((int)fecha1->mes - (int)fecha2->mes);
    }
    return sgn((int)fecha1->dia - (int)fecha2->dia);
}

// Función para imprimir una fecha representada por un objeto de tipo TFecha
void imprimirTFecha(TFecha fecha) {
    printf("%u/%u/%u", fecha->dia, fecha->mes, fecha->anio);
}


// Función para obtener el día del mes de la fecha.
nat diaTFecha(TFecha fecha){
    return fecha->dia;
}

// Función para obtener el mes de la fecha.
nat mesTFecha(TFecha fecha){
    return fecha->mes;
}

// Función para obtener el anio de la fecha.
nat anioTFecha(TFecha fecha){
    return fecha->anio;
}

