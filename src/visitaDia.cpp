#include "../include/visitaDia.h"
#include <math.h>
#include <assert.h>

struct rep_nodo{
  float edadPromedio;
  TGrupoABB grupo;
};                                                                                
typedef struct rep_nodo *nodo;


//to do: cambiar ubicacionGrupo por un array de nodo y que apunte a el grupo directo en vez de su ubicacion, multiTAD
struct rep_visitadia{
  int cantidad;
  int cota;
  TFecha fecha;
  nodo* grupos;
  //conjunto que relaciona id%10000 con su ubicacion dentro del heap, conjunto
  int* ubicacionGrupo;
  bool invertido;
};
//to do, cambiar a N+1 ubicacion;
TVisitaDia crearTVisitaDia(TFecha fecha, int N){
  TVisitaDia nuevaVisitaDia = new rep_visitadia;
  nuevaVisitaDia->cantidad = 0;
  nuevaVisitaDia->cota = N;
  nuevaVisitaDia->fecha = fecha;
  nuevaVisitaDia->grupos = new nodo[N+1];
  nuevaVisitaDia->ubicacionGrupo = new int[1000000];
  nuevaVisitaDia->invertido = false;
  
  for (int i = 0; i < N; i++)
  {
    nuevaVisitaDia->grupos[i] = NULL;
  }
  for(int i = 0; i < 10000; i++ ){
    nuevaVisitaDia->ubicacionGrupo[i] = 0;
  }
  
  return nuevaVisitaDia;
}


/*Filtrados e inscercion (normal e invertido)
------------------------------------------------------------------------*/

void filtradoAscendente(TVisitaDia &visita, int i){
  while (i/2 != 0 && visita->grupos[i]->edadPromedio < visita->grupos[i/2]->edadPromedio)
  {
    nodo nodoAux = visita->grupos[i/2];
    visita->grupos[i/2] = visita->grupos[i];
    visita->grupos[i] = nodoAux;
    visita->ubicacionGrupo[i%10000] = i/2;
    visita->ubicacionGrupo[(i/2)%10000] = i;
    i = i/2;
  }
}

void filtradoAscendenteInverso(TVisitaDia visita, int i){
  while (i/2 != 0 && visita->grupos[i]->edadPromedio > visita->grupos[i/2]->edadPromedio)
  {
    nodo nodoAux = visita->grupos[i/2];
    visita->grupos[i/2] = visita->grupos[i];
    visita->grupos[i] = nodoAux;
    visita->ubicacionGrupo[i%10000] = i/2;
    visita->ubicacionGrupo[(i/2)%10000] = i;
    i = i/2;
  }
}


void filtradoDescendente(TVisitaDia &visita, int i, bool insertar){

  if (2*i <= visita->cantidad)
  {
    nodo aux = visita->grupos[i];
    int hijo = 2*i;
    if((hijo+1 <= visita->cantidad) &&
     (visita->grupos[hijo+1]->edadPromedio < visita->grupos[hijo]->edadPromedio))
    {
      hijo = hijo + 1;
    }
    
    visita->grupos[i] = visita->grupos[hijo];
    visita->ubicacionGrupo[idGrupo(visita->grupos[i]->grupo)%10000] = i;
    //si no se esta insertando necesitamdo que sea un swap
    if(!insertar){
      visita->grupos[hijo] = aux;
      visita->ubicacionGrupo[idGrupo(visita->grupos[hijo]->grupo)%10000] = hijo;
    }
    filtradoDescendente(visita, hijo, insertar);
  }else{
    //si se esta insertando necesitamos corregir el hueco que queda en la ultima de las hojas
    if(insertar){
      visita->grupos[i] = visita->grupos[visita->cantidad];
      visita->ubicacionGrupo[idGrupo(visita->grupos[i]->grupo)%10000] = i;

      visita->grupos[visita->cantidad] = NULL; 
    }
    

  }
}

void filtradoDescendenteInverso(TVisitaDia &visita, int i, bool insertar){

  if (2*i <= visita->cantidad)
  {
    nodo aux = visita->grupos[i];
    int hijo = 2*i;
    if((hijo+1 <= visita->cantidad) &&
     (visita->grupos[hijo+1]->edadPromedio > visita->grupos[hijo]->edadPromedio))
    {
      hijo = hijo + 1;
    }
    visita->grupos[i] = visita->grupos[hijo];
    visita->ubicacionGrupo[idGrupo(visita->grupos[i]->grupo)%10000] = i;

    if(!insertar){
      visita->grupos[hijo] = aux;
      visita->ubicacionGrupo[idGrupo(visita->grupos[hijo]->grupo)%10000] = hijo;
    }
    filtradoDescendenteInverso(visita, hijo, insertar);
  }else{
    //si se esta insertando necesitamos corregir el hueco que queda en la ultima de las hojas
    if(insertar){
      visita->grupos[i] = visita->grupos[visita->cantidad];
      visita->ubicacionGrupo[idGrupo(visita->grupos[i]->grupo)%10000] = i;

      visita->grupos[visita->cantidad] = NULL; 
    }
    

  }
}

/*------------------------------------------------------------------------*/



void encolarGrupoTVisitaDia(TVisitaDia &visita, TGrupoABB grupo){

  if(visita->cota > visita->cantidad){
    nodo aux = new rep_nodo;
    aux->grupo = grupo;
    aux->edadPromedio = edadPromedioTGrupoABB(grupo);
    visita->cantidad++;
    visita->ubicacionGrupo[idGrupo(grupo)%10000] = visita->cantidad;

    visita->grupos[visita->cantidad] = aux;
    
    if (visita->cantidad > 1)
    {
      if(visita->invertido){
        int i = visita->cantidad;
        filtradoAscendenteInverso(visita, i);
      }else{
        int i = visita->cantidad;
        filtradoAscendente(visita, i);
      }
    }
   aux = NULL;
  }
}
 

int cantidadGruposTVisitaDia(TVisitaDia visitaDia){
  return visitaDia->cantidad;
}

void imprimirTVisitaDia(TVisitaDia visitaDia){
  printf("Visita para dia: ");
  imprimirTFecha(visitaDia->fecha);
  int nivel= 0;
  printf("\n");

  //va incrementeando la conta inferior de los niveles
  while (int(pow(2, nivel))<= visitaDia->cantidad)
  {
    printf("\n");
    printf("Nivel %d\n", nivel+1);

    int i = int(pow(2, nivel));

    //imprme a partir del primero del nivel 2^nivel hasta el ultimo (2^nivel+1)-1
    while (i <= visitaDia->cantidad && i < int(pow(2, nivel+1)))
    {
      printf("%d) Grupo %d con edad promedio %5.2f\n", i, idGrupo(visitaDia->grupos[i]->grupo), visitaDia->grupos[i]->edadPromedio);
      imprimirTGrupoABB(visitaDia->grupos[i]->grupo);
      i++;

    }
    nivel++;
    
  }
}

TGrupoABB desencolarGrupoTVisitaDia(TVisitaDia &visitaDia){
  if(visitaDia->cantidad > 0){
    nodo borrarNodo = visitaDia->grupos[1];
    TGrupoABB grupoRetorno = visitaDia->grupos[1]->grupo;
    visitaDia->grupos[1] = NULL;
    if(visitaDia->cantidad > 1){
      if(visitaDia->invertido){
        filtradoDescendenteInverso(visitaDia, 1, true);
      }else{
        filtradoDescendente(visitaDia, 1, true); 
      }
      

    }else{
      visitaDia->grupos[1] = NULL;
    }
    visitaDia->cantidad--;
    visitaDia->ubicacionGrupo[idGrupo(borrarNodo->grupo)] = 0;
    delete borrarNodo;
    borrarNodo = NULL;

    return grupoRetorno;
  }
  return NULL;
}

void liberarTVisitaDia(TVisitaDia &visitaDia){
  for (int i = 0; i <= visitaDia->cantidad; i++)
  {
    if(visitaDia->grupos[i] != NULL){
      liberarTGrupoABB(visitaDia->grupos[i]->grupo);
    }
    
    delete visitaDia->grupos[i];
  }
  delete [] visitaDia->grupos;

  liberarTFecha(visitaDia->fecha);
  delete [] visitaDia->ubicacionGrupo;
  
  delete visitaDia;
  visitaDia = NULL;
}
void liberarVisitaSinGrupo(TVisitaDia &visita){
  for (int i = 0; i <= visita->cantidad; i++){
    delete visita->grupos[i];
  }
  
  delete [] visita->ubicacionGrupo;
  visita->ubicacionGrupo = NULL;
  delete [] visita->grupos;
  visita->grupos = NULL;
  visita->fecha = NULL;
  delete visita;
  visita = NULL;
}
void invertirPrioridadTVisitaDia(TVisitaDia &visita) {
  visita->invertido = !visita->invertido;
  if(visita->cantidad > 1){
    if(visita->invertido){
      for (int i = visita->cantidad/2; i > 0; i--)
      {
        filtradoDescendenteInverso(visita, i, false);
      }
      }else{
        for (int i = visita->cantidad/2; i > 0; i--)
        {
          filtradoDescendente(visita, i, false);
        }
    }
  }
  
  
  
  // visita->invertido = !visita->invertido;
  // if(visita->cantidad > 1){
  //   TVisitaDia visitaDiaInvertida = crearTVisitaDia(visita->fecha, visita->cota);
  //   visitaDiaInvertida->invertido = visita->invertido;
  //   if (visitaDiaInvertida->invertido){
  //     for (int i = visita->cantidad; i > 0; i--){
  //       encolarGrupoTVisitaDia(visitaDiaInvertida, visita->grupos[i]->grupo);
  //     }
  //   }else{
  //     for (int i = 1; i <= visita->cantidad; i++){
  //       encolarGrupoTVisitaDia(visitaDiaInvertida, visita->grupos[i]->grupo);
  //     }
  //   }
    
    

  //   liberarVisitaSinGrupo(visita);
  //   visita = visitaDiaInvertida;

  //   visitaDiaInvertida = NULL;
  // }

}

bool estaEnTVisitaDia(TVisitaDia visita, int id) {
  return visita->ubicacionGrupo[id%10000] != 0;
} 

float prioridadTVisitaDia(TVisitaDia visita, int id){
  int ubicacion = visita->ubicacionGrupo[id];
  return visita->grupos[ubicacion]->edadPromedio;
}

TGrupoABB masPrioritarioTVisitaDia(TVisitaDia visita){
	if(visita->cantidad > 0){
    return visita->grupos[1]->grupo;
  }
  return NULL;
}


int maxGruposTVisitaDia(TVisitaDia visita){
  return visita->cota;
}

TFecha fechaTVisitaDia(TVisitaDia visitaDia){
  return visitaDia->fecha;
}


