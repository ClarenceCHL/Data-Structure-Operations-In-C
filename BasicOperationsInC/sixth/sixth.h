#include <stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode* left;
    struct treeNode* right;
};
struct treeNode* tree=NULL;

struct treeNode* createTree(int num){
    struct treeNode* root=(struct treeNode*)malloc(sizeof(struct treeNode));
    root->value=num;
    root->left=NULL;
    root->right=NULL;
    return root;
}

void add(int num){
    if (tree==NULL){
        tree=createTree(num);
        return;
    }
    struct treeNode* ptr=tree;
    struct treeNode* prev=NULL;
    while(ptr!=NULL){
        prev=ptr;
        if(num<ptr->value){
            ptr=ptr->left;
        }else if(num>ptr->value){
            ptr=ptr->right;
        }else{
            return;
        }
    }
    if(prev->value>num){
        prev->left=createTree(num);
    }else{
        prev->right=createTree(num);
    }
}

void inorderTraverse(struct treeNode* root){
    if(root==NULL)return;
    inorderTraverse(root->left);
    printf("%d\t",root->value);
    inorderTraverse(root->right);
}
