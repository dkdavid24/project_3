//
// Created by Horvath on 2021. 05. 26..
//

#include "hash.h"
#include <math.h>

hash createTable(int capacity) {
    hash tabla;
    tabla.capacity = capacity;
    tabla.currentSize = 0;
    tabla.names = (Name *) malloc(capacity * sizeof(Name));
    for (int i = 0; i < tabla.capacity; i++) {
        tabla.names[i] = emptyName();
    }
    return tabla;
}

int hashPos(Name name) {
    int numOfLett = (int) (strlen(name.firstName) + strlen(name.lastName));
    int result = 0;
    char *strName = (char *) malloc((numOfLett + 1) * sizeof(char));
    strcpy(strName, name.firstName);
    strcat(strName, name.lastName);
    numOfLett--;
    while (numOfLett >= 0) {
        result += (int) strName[numOfLett] * (int) pow(2, numOfLett);
        numOfLett--;
    }
    return result;

}

void insertTable(hash *tabla, Name name) {
    int j, i = 0;
    int sz = hashPos(name);
    if ((*tabla).currentSize == (*tabla).capacity) {
        printf("Hash is full");
        return;
    }
    do {
        j = (sz + i) % (*tabla).capacity;
        if ((*tabla).names[j].firstName == NULL) {
            setName((*tabla).names + j, name);
            (*tabla).currentSize++;
            return;
        } else i++;
    } while (i <= (*tabla).capacity);
}

void deleteHash(hash *table, Name name) {
    int j, i = 0;
    int sz = hashPos(name);
    do {
        j = (sz + i) % (*table).capacity;
        if ((*table).names[j].firstName != NULL) {
            if (compareName((*table).names[j], name) == 0) {
                freeName((*table).names[j]);
                (*table).names[j] = emptyName();
                return;
            }
        }
        i++;
    } while ((*table).names[j].firstName != NULL && i <= (*table).capacity);
    if (i != (*table).capacity) {
//        printf("There is no such a person on the list");
    }
}

bool searchHash(hash *tabla, Name name) {
    int j, i = 0;
    int sz = hashPos(name);
    do {
        j = (sz + i) % (*tabla).capacity;
        if ((*tabla).names[j].firstName != NULL) {
            if (compareName((*tabla).names[j], name) == 0) {
                return true;
            }
        }
        i++;
    } while ((*tabla).names[j].firstName != NULL && i <= (*tabla).capacity);
    return false;
}

void listTable(hash *table) {
    for (int i = 0; i < table->capacity; i++) {
        if (table->names[i].firstName != NULL) {
            printf("Name:%s %s\n", table->names[i].firstName, table->names[i].lastName);

        }
    }
}