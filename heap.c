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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * new = (Heap *)malloc(sizeof(Heap));
  new->capac = 2;
  new->size = 0;
  new->heapArray = (heapElem *)malloc(3*sizeof(heapElem));
  for(int i ; i < new->capac ; i++)
  {
    new->heapArray[i].data = NULL;
    new->heapArray[i].priority = 0;
  }
  return new;
}
