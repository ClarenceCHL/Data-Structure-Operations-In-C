#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int isV(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        return 1;
    }
    return 0;
}