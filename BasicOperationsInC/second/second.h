#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct LLnode{
    int value;
    struct LLnode* next;
};

int countNode(struct LLnode* root){
    struct LLnode* ptr = root;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    return count;
}
void printLL(struct LLnode* root, int num){
    if(num==0){
        printf("\n");
        return;
    }
    int value=root->value;
    printf("%d\t",value);
    while(root->next!=NULL){
        if(root->next->value!=value){
            value=root->next->value;
            printf("%d\t",value);
        }
        root=root->next;
    }
    printf("\n");
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

struct LLnode* removeNode(int target, struct LLnode* root){
    if(root==NULL)return root;
    if(root->next==NULL&&root->value==target){
        return NULL;
    }
    if(root->value==target){
        return root->next;
    }
    struct LLnode* ptr=root;
    while(ptr->next!=NULL){
        if(ptr->next->value==target){
            ptr->next=ptr->next->next;
            return root;
        }
        ptr=ptr->next;
    }
    return root;
    
}