//
// Created by dkdav on 2021-05-26.
//

#include "linked_list.h"

Node *createListNode(Name name) {
    Node *res = (Node *) malloc(sizeof(Node));
    res->data = name;
    res->next = NULL;
    return res;
}

void insertList(Node **rootPTR, Name name) {
    if (*rootPTR == NULL) {
        (*rootPTR) = createListNode(name);
        return;
    }
    Node *new = createListNode(name);
    new->next = *rootPTR;
    *rootPTR = new;
}

void deleteFromList(Node **rootPTR, Name value) {
    if (compareName((*rootPTR)->data, value) == 0) {
        Node *temp = *rootPTR;
        *rootPTR = (*rootPTR)->next;
        freeName(temp->data);
        free(temp);
        return;
    }
    Node *p = *rootPTR;
    while (p->next != NULL) {
        if (compareName(p->next->data, value) == 0) {
            Node *temp = p->next;
            p->next = p->next->next;
            freeName(temp->data);
            free(temp);
            return;
        }
        p = p->next;
    }
}

bool inList(Node *root, Name value) {
    Node *p = root;
    while (p != NULL) {
        if (compareName(p->data, value) == 0) {
            return true;
        }
        p = p->next;
    }
    return false;
}

Node *getList(Node *root, Name value) {
    Node *p = root;
    while (p != NULL) {
        if (compareName(p->data, value) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void utilPrintList(Node *root) {
    Node *p = root;
    while (p != NULL) {
        printf("%s\n", nameToStr(p->data));
        p = p->next;
    }
}
