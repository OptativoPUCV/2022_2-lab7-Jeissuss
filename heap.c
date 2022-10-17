#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  int i = 0;
  
  if(pq->size == 0)
    return NULL;
  else
    return pq->heapArray[i].data;

  return NULL;

}



void heap_push(Heap* pq, void* data, int priority){
  int i = 0;
  int talla = pq->size;
  if(pq->capac == pq->size)
  {
    pq->capac = (pq->capac*2)+1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac*sizeof(heapElem)); 
  }
  pq->heapArray[talla].data = data;
  pq->heapArray[talla].priority = priority;
  pq->size = talla+1;
  for(i = pq->size ; i>= 0 ; i--)
  {
    int posActual = i -1;
    int padre = (posActual - 1)/2;
    if(pq->heapArray[posActual].priority > pq->heapArray[padre].priority)
    {
      int auxPrio = pq->heapArray[padre].priority;
      void* auxData = pq->heapArray[padre].data;
      pq->heapArray[padre].priority = pq->heapArray[posActual].priority;
      pq->heapArray[padre].data = pq->heapArray[posActual].data;
      pq->heapArray[posActual].priority = auxPrio;
      pq->heapArray[posActual].data = auxData;
    }
}


void heap_pop(Heap* pq){
  int talla = pq->size;
  
  int auxPrio = pq->heapArray[talla -1].priority;
  void* auxData = pq->heapArray[talla -1].data;
  
  printf("\n");
  pq->heapArray[talla].priority = pq->heapArray[0].priority;
  pq->heapArray[talla].data = pq->heapArray[0].data;
  pq->heapArray[0].priority = auxPrio;
  pq->heapArray[0].data = auxData;
  pq->heapArray[talla -1].priority = 0;
  pq->heapArray[talla -1].data = NULL;
  pq->size = talla - 1;
  
  for(int i = 0 ; i < pq->size-1 ; i++)
  {
    
  }
}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->capac = 3;
  new->size = 0;
  new->heapArray = (heapElem *)malloc(3*sizeof(heapElem));
  
  for (int i=0 ; i < new->capac ; i++)
  {
    new->heapArray[i].data = NULL;
    new->heapArray[i].priority = 0;
  }
  return new;
}