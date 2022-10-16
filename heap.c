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
  
  
}


void heap_pop(Heap* pq){

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