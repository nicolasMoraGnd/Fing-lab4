/*
  Módulo de definición de 'utils'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>  // printf, scanf, sprintf

// tipo para los enteros no negativos
typedef unsigned int nat;

// tipos para arreglos
// typedef nat *ArregloNats;       // arreglo de nat
// typedef char *ArregloChars;     // arreglo de char
// typedef bool *ArregloBools;     // arreglo de bool
// typedef double *ArregloDoubles; // arreglo de double

// leen desde la entrada estándar y devuelven el elemento leído
nat leerNat();
int leerInt();
char leerChar();
double leerDouble();

/*
  Lee en 'cs' desde la entreada estándar.
 */
void leerChars(char* cs);

/*
  Lee en 'cs' el resto de la línea de la entrada estandar sin consumir
  el cambi de línea.
 */
void leerRestoLinea(char* cs);

#endif