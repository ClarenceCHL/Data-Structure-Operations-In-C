#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int collisionNum = 0;
int searchNum = 0;

struct LLnode{
    int value;
    struct LLnode* next;
};

struct HashTable
{
    int index;
    struct LLnode* node;
};

void printNum(){
    printf("%d\n%d\n",collisionNum,searchNum);
}

struct LLnode* createNode(int num,struct LLnode* next){
    struct LLnode* root = (struct LLnode*) malloc(sizeof(struct LLnode));
    root->value=num;
    root->next=next;
    return root;
}
void freeLL(struct LLnode* root){
    if(root==NULL)return;
    freeLL(root->next);
    free(root);
}
struct LLnode* addNode(int num, struct LLnode* root){
    if(root==NULL){
       return createNode(num,NULL);
    }
    collisionNum++;
    if(root->value>=num){
        return createNode(num,root);
    }
    struct LLnode* ptr=root;
    while(ptr->next!=NULL){
        if(ptr->next->value>=num){
            ptr->next=createNode(num,ptr->next);
            return root;
        }
        ptr=ptr->next;
    }
    ptr->next=createNode(num,NULL);
    return root;
}

int search(struct LLnode* root,int target){
    struct LLnode* ptr=root;
    while(ptr!=NULL){
        if(ptr->value==target){
            return 1;
        }
        ptr=ptr->next;
    }
    return 0;
}


