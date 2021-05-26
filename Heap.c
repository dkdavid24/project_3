//
// Created by Robi on 2021. 05. 25..
//

#include "Heap.h"

Heap* createHeap(){
    Heap* newHeap=(Heap*)malloc(sizeof(Heap));
    newHeap->size=0;
    newHeap->names=(Name*)malloc(newHeap->size*sizeof(Name));

    return newHeap;
}

Heap* insertInHeap(Heap* heap,Name name){
    if(heap==NULL){
        heap=createHeap();
    }

    heap->size++;
    heap->names=(Name*)realloc(heap->names,heap->size*sizeof(Name));
    heap->names[heap->size-1]=name;
    up(heap,heap->size-1);

    return heap;
}

void up(Heap* heap,int index){
    Name temp;

    while(index>0 && compareName(heap->names[(index-1)/2],heap->names[index])<0){
        temp=heap->names[(index-1)/2];
        heap->names[(index-1)/2]=heap->names[index];
        heap->names[index]=temp;
        index=(index-1)/2;
    }
}