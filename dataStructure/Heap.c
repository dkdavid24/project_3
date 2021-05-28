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

void down(Heap* heap,int index){
    Name temp;
    int tempIndex;

    while(2*index+1<heap->size){
        tempIndex=2*index+1;
        if(tempIndex<heap->size && compareName(heap->names[tempIndex],heap->names[tempIndex+1])<0){
            tempIndex++;
        }
        if(compareName(heap->names[tempIndex],heap->names[index])<=0){
            return;
        }
        temp=heap->names[index];
        heap->names[index]=heap->names[tempIndex];
        heap->names[tempIndex]=temp;
        index=tempIndex;
    }
}

int searchInHeap(Heap* heap,Name name){
    for(int i=0;i<heap->size;i++){
        if(compareName(heap->names[i],name)==0){
            return i;
        }
    }
    return -1;
}

Heap* deleteFromHeap(Heap* heap,Name name){
    int index=searchInHeap(heap,name);

    if(index==-1){
        return heap;
    }

    heap->names[index]=heap->names[heap->size-1];
    heap->size--;
    heap->names=(Name*)realloc(heap->names,heap->size*sizeof(Name));
    down(heap,index);

    return heap;
}

void printHeap(Heap* heap){
    for(int i=0;i<heap->size;i++){
        printf("%s\n",nameToStr(heap->names[i]));
    }
    printf("\n");
}