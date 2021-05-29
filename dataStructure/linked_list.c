//
// Created by dkdav on 2021-05-26.
//

#include "linked_list.h"

List *createListNode(Name name) {
    List *res = (List *) malloc(sizeof(List));
    res->data = name;
    res->next = NULL;
    return res;
}

void insertList(List **rootPTR, Name name) {
    if (*rootPTR == NULL) {
        (*rootPTR) = createListNode(name);
        return;
    }
    List *new = createListNode(name);
    new->next = *rootPTR;
    *rootPTR = new;
}

void deleteFromList(List **rootPTR, Name value) {
    if (compareName((*rootPTR)->data, value) == 0) {
        List *temp = *rootPTR;
        *rootPTR = (*rootPTR)->next;
        freeName(temp->data);
        free(temp);
        return;
    }
    List *p = *rootPTR;
    while (p->next != NULL) {
        if (compareName(p->next->data, value) == 0) {
            List *temp = p->next;
            p->next = p->next->next;
            freeName(temp->data);
            free(temp);
            return;
        }
        p = p->next;
    }
}

bool inList(List *root, Name value) {
    List *p = root;
    while (p != NULL) {
        if (compareName(p->data, value) == 0) {
            return true;
        }
        p = p->next;
    }
    return false;
}

List *getList(List *root, Name value) {
    List *p = root;
    while (p != NULL) {
        if (compareName(p->data, value) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void utilPrintList(List *root) {
    List *p = root;
    while (p != NULL) {
        printf("%s\n", nameToStr(p->data));
        p = p->next;
    }
}
