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