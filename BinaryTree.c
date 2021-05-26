//
// Created by Robi on 2021. 05. 25..
//

#include "BinaryTree.h"

Root* createRoot(){
    Root* newRoot=(Root*)malloc(sizeof(Root));
    newRoot->right=NULL;
    newRoot->left=NULL;

    return newRoot;
}

Root* insertInTree(Root* root,Name name){
    if(root==NULL){
        root=createRoot();
        root->name=name;
        return root;
    }

    if(compareName(root->name,name)>0){
        root->left=insertInTree(root->left,name);
    }

    else if(compareName(root->name,name)<0){
        root->right=insertInTree(root->right,name);
    }

    return root;
}

bool searchInTree(Root* root,Name name){
    if(root==NULL){
        return false;
    }

    if(compareName(root->name,name)>0){
        return searchInTree(root->left,name);
    }

    if(compareName(root->name,name)<0){
        return searchInTree(root->right,name);
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