#include "second.h"

int main(int argc,char** argv){

    FILE * fp=fopen(argv[1],"r");
    if(fp == NULL){
        printf("error\n");
        return 0;
    }
    char c;int num;
    struct LLnode* root=NULL;
    while(fscanf(fp,"%c",&c)!=EOF){
        fscanf(fp,"%d",&num);
        if(c=='i'){
            root=addNode(num,root);
        }else if(c=='d'){
            root=removeNode(num,root);
        }
    }
    printf("%d\n",countNode(root));
    printLL(root,countNode(root));
    fclose(fp);
    freeLL(root);
    return 0;
}