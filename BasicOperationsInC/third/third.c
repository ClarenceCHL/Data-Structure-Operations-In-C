#include "third.h"

int main(int argc,char** argv){
    FILE * fp=fopen(argv[1],"r");
    if(fp == NULL){
        printf("error\n");
        return 0;
    }
    char c;
    int num;
    struct HashTable** table=(struct HashTable**)malloc(sizeof(struct HashTable*)*10000);
    for(int i=0;i<10000;i++){
        table[i]=(struct HashTable*)malloc(sizeof(struct HashTable));
        table[i]->index=i;
        table[i]->node=NULL;
    }
    while(fscanf(fp,"%c",&c)!=EOF){
        fscanf(fp,"%d",&num);
        int index=num%10000;
        if(index<0){
            index=index*(-1);
        }
        if(c=='i'){
            table[index]->node=addNode(num,table[index]->node);
        }else if(c=='s'){
            searchNum+=search(table[index]->node,num);
        }
    }
    printNum();
    fclose(fp);
    for(int i=0;i<10000;i++){
        freeLL(table[i]->node);
    }
    free(table);
    return 0;
}