#include "sixth.h"

int main(int argc,char** argv){

    FILE * fp=fopen(argv[1],"r");
    char c; int num;
    while(fscanf(fp,"%c\t%d\n",&c,&num)!=EOF){
        add(num);
    }
    inorderTraverse(tree);
    printf("\n");
    fclose(fp);
    free(tree);
    return 0;
}