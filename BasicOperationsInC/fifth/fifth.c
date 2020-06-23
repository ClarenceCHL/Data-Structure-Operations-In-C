#include "fifth.h"

int main(int argc,char** argv){
    for(int i=1;i<argc;i++){
        char str[999];
        strcpy(str,argv[i]);
        for(int j=0;j<strlen(str);j++){
            if(isV(str[j])==1){
                printf("%c",str[j]);
            }
        }
    }
    printf("\n");
    return 0;
}