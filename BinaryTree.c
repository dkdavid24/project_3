//
// Created by Robi on 2021. 05. 25..
//

#include "BinaryTree.h"

Root* create(){
    Root* newRoot=(Root*)malloc(sizeof(Root));
    newRoot->right=NULL;
    newRoot->left=NULL;

    return newRoot;
}

Root* insert(Root* root,Name name){
    if(root==NULL){
        root=create();
        root->name=name;
        return root;
    }

    if(compareName(root->name,name)>0){
        root->left=insert(root->left,name);
    }

    else if(compareName(root->name,name)<0){
        root->right=insert(root->right,name);
    }

    return root;
}

bool search(Root* root,Name name){
    if(root==NULL){
        return false;
    }

    if(compareName(root->name,name)>0){
        return search(root->left,name);
    }

    if(compareName(root->name,name)<0){
        return search(root->right,name);
    }

    return true;
}

Root* delete(Root* root,Name name){
    if(root==NULL){
        return root;
    }

    if(compareName(root->name,name)>0){
        root->left=delete(root->left,name);
    }
    else if(compareName(root->name,name)<0){
        root->right=delete(root->right,name);
    }
    else{
        if(root->left==NULL){
            Root* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Root* temp=root->left;
            free(root);
            return temp;
        }

        Root* temp=first(root->right);
        root->name=temp->name;
        root->right=delete(root->right,temp->name);
    }

    return root;
}

Root* first(Root* root){
    if(root==NULL){
        return root;
    }

    while(root->left!=NULL){
        root=root->left;
    }

    return root;
}

void printTree(Root* root){
    if(root==NULL){
        return;
    }

    if(root->left!=NULL){
        printTree(root->left);
    }
    printf("%s\n", nameToStr(root->name));

    if(root->right!=NULL){
        printTree(root->right);
    }
}