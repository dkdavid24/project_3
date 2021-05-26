//
// Created by Horvath on 2021. 05. 25..
//

#include "array.h"

Array createArray(){
    Array res;
    res.size=50;
    res.count=0;
    res.names=(Name*)malloc((res.size)*sizeof(Name));
    return res;
}
void addName(Array *res,Name name){
    if(res->count==res->size){
        res->size=2*res->size;
        res->names=(Name*)realloc(res->names,res->size*(sizeof(Name)));
    }
    res->names[res->count]=name;
    res->count++;

}
bool findName(Array *res,Name name){
    for(int i=0;i<res->count;i++){
        if(compareName(res->names[i],name)==0){
            return true;
        }
    }
    return false;
}
void deleteName(Array *res,Name name){
    for(int i=0;i<res->count;i++){
        if(compareName(name,res->names[i])==0){
            for(int j=i;j<res->count-1;j++){
                res->names[j]=res->names[j+1];
            }
            res->count--;
            return;
        }
    }
}
void listName(Array *res){
    for(int i=0;i<res->count;i++){
        printf("Name:%s %s\n",res->names[i].firstName,res->names[i].lastName);
    }
}
