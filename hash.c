//
// Created by Horvath on 2021. 05. 26..
//

#include "hash.h"
hash createTable(int capacity){
    hash tabla;
    tabla.capacity=capacity;
    tabla.currentSize=0;
    tabla.names=(Name*)malloc(capacity*sizeof(Name));
    for(int i=0;i<tabla.capacity;i++){
        tabla.names[i].firstName='/0';
    }
    return tabla;
}
void insertTable(hash *tabla, Name name){
    int j,i=0;
    int sz=strlen(name.firstName)+strlen(name.lastName);
    if((*tabla).currentSize==(*tabla).capacity){
        printf("Hash is full");
        return;
    }
    do{
        j=(sz+i)%(*tabla).capacity;
        if((*tabla).names[j].firstName=='/0'){
            (*tabla).names[j]=name;
            (*tabla).currentSize++;
            return;
        }
        else i++;
    }while(i<=(*tabla).capacity);
}
void deleteHash(hash *table, Name name){
    int j,i=0;
    int sz=strlen(name.firstName)+strlen(name.lastName);
    do{
        j=(sz+i)%(*table).capacity;
        if((strlen((*table).names[j].firstName) + strlen((*table).names[j].lastName)) == sz){
            (*table).names[j].firstName='/0';
            (*table).names[j].lastName='/0';
            return;
        }
        else{
            i++;
        }
    }while((*table).names[j].firstName != '/0' && i <= (*table).capacity);
    if(i!=(*table).capacity){
        printf("There is no such a person on the list");
    }
}
bool searchHash(hash *tabla, Name name){
    int j,i=0;
    int sz=strlen(name.firstName)+strlen(name.lastName);
    do{
        j=(sz+i)%(*tabla).capacity;
        if((strlen((*tabla).names[j].firstName)+strlen((*tabla).names[j].lastName))==sz){
            return true;
        }
        else{
            i++;
        }
    }while((*tabla).names[j].firstName!='/0' && i<=(*tabla).capacity);
    return false;
}
void listTable(hash *table){
    for(int i=0;i<table->capacity;i++){
        if(table->names[i].firstName!='/0'){
            printf("Name:%s %s\n",table->names[i].firstName,table->names[i].lastName);

        }
    }
}